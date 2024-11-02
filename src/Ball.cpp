// Ball.cpp - Source file for Ball class

#include "Ball.h"

#include <SDL.h>
#include <cmath>

#include "Game.h"

void Ball::init(const Vec2<int> position, const Vec2<unsigned int> size, const Colour colour, const Vec2<int> default_position, const unsigned int speed)
{
    this->position = position;
    this->default_position = default_position;
    this->size = size;
    this->colour = colour;
    this->speed = speed;
    velocity = (Vec2<int>) {0, 0};
}
    
Vec2<int> Ball::getPosition()
{
    return position;
}

void Ball::setPosition(const Vec2<int> position)
{
    this->position = position;
}

Vec2<int> Ball::getDefaultPosition()
{
    return position;
}

void Ball::setDefaultPosition(const Vec2<int> position)
{
    this->default_position = position;
}

Vec2<unsigned int> Ball::getSize()
{
    return size;
}

void Ball::setSize(const Vec2<unsigned int> size)
{
    this->size = size;
}

Colour Ball::getColour()
{
    return colour;
}

void Ball::setColour(const Colour colour)
{
    this->colour = colour;
}

unsigned int Ball::getSpeed()
{
    return speed;
}

void Ball::setSpeed(const unsigned int speed)
{
    this->speed = speed;
}

Vec2<int> Ball::getVelocity()
{
    return velocity;
}

void Ball::setVelocity(const Vec2<int> velocity)
{
    this->velocity = velocity;
}

bool Ball::isFrozen()
{
    return is_frozen;
}

void Ball::freeze()
{
    is_frozen = true;
}

void Ball::unfreeze()
{
    is_frozen = false;
}

void Ball::setOutOfBoundsCallback(std::function<void()> callback)
{
    outOfBoundsCallback = callback;
}


// Returns side of ball that experiences collision
Direction Ball::collisionWithPaddle(Paddle paddle)
{
    PaddleType paddle_type = paddle.getPaddleType();
    Vec2<int> paddle_position = paddle.getPosition();
    Vec2<unsigned int> paddle_size = paddle.getSize();
    
    // If the ball is at the same y-position as the paddle
    if (!(position.y <= paddle_position.y + paddle_size.y && position.y >= paddle_position.y) &&
    !(position.y + size.y <= paddle_position.y + paddle_size.y && position.y + size.y >= paddle_position.y))
    {
        return None;
    }

    if (paddle_type == Player1)
    {
        if (velocity.x < 0 && position.x <= paddle_position.x + paddle_size.x && position.x >= paddle_position.x)
        {
            return Left;
        }
    }

    if (paddle_type == Player2)
    {
        if (velocity.x > 0 && position.x + size.x >= paddle_position.x && position.x + size.x <= paddle_position.x + paddle_size.x)
        {
            return Right;
        }
    }

    if (position.x + size.x >= paddle_position.x && position.x <= paddle_position.x + static_cast<int>(paddle_size.x)
    && position.y >= paddle_position.y && position.y <= paddle_position.y + static_cast<int>(paddle_size.y))
    {
        return None;
    }
    return None;
}

float Ball::angleOfCollision(Paddle paddle, Direction side_of_impact)
{
    PaddleType paddle_type = paddle.getPaddleType();
    Vec2<int> paddle_position = paddle.getPosition();
    Vec2<unsigned int> paddle_size = paddle.getSize();

    float distance_from_centre = (position.y + size.y / 2) - (paddle_position.y + paddle_size.y / 2);
    return (distance_from_centre / (paddle_size.y / 2)) * M_PI_2;
}

Vec2<int> Ball::velocityAfterCollision(Paddle paddle)
{
    PaddleType paddle_type = paddle.getPaddleType();
    Vec2<int> paddle_position = paddle.getPosition();
    Vec2<unsigned int> paddle_size = paddle.getSize();

    Vec2<int> direction = {0, 0};
    if (paddle_type == Player1)
    {
        direction.x = 1;
    }
    else
    {
        direction.x = -1;
    }

    if (position.y - size.y / 2 > paddle_position.y - paddle_size.y / 2)
    {
        direction.y = 1;
    }
    else
    {
        direction.y = -1;
    }

    float distance_from_centre = (position.y + size.y / 2) - (paddle_position.y + paddle_size.y / 2);
    float percent_from_centre = std::abs(distance_from_centre / (paddle_size.y / 2));
    float velocity_norm = std::sqrt(std::pow(velocity.x, 2) + std::pow(velocity.y, 2));

    Vec2<double> most_angled_velocity = (Vec2<double>) {velocity_norm * std::sin(M_PI / 4), velocity_norm * std::cos(M_PI / 4)}; // first application of analysis
    Vec2<int> final_velocity = (Vec2<int>) {direction.x * static_cast<int>(percent_from_centre * most_angled_velocity.x + (1 - percent_from_centre) * velocity_norm), direction.y * static_cast<int>((1 - percent_from_centre) * most_angled_velocity.y + percent_from_centre * velocity_norm)};
    
    if (final_velocity.x == 0)
    {
        final_velocity.x = direction.x;
    }

    printf("distance %f, percent %f, norm %f, most angled velocity (%f, %f), final velocity (%d, %d)\n", distance_from_centre, percent_from_centre, velocity_norm, most_angled_velocity.x, most_angled_velocity.y, final_velocity.x, final_velocity.y);

    return final_velocity;
}

Direction Ball::collisionWithWall(const int screen_height)
{
    if (position.y <= 0)
    {
        return Up;
    }
    else if (position.y + size.y >= screen_height)
    {
        return Down;
    }
    return None;
}

Direction Ball::outOfBounds(const int screen_width)
{
    if (position.x <= 0)
    {
        return Left;
    }
    else if (position.x + size.x >= screen_width)
    {
        return Right;
    }

    return None;
}

void Ball::handleCollision()
{
    /* if (collisionWithPaddle(Game::player) != None || collisionWithPaddle(Game::opponent) != None)
    {
        velocity.x *= -1;
    } */
    if (collisionWithPaddle(Game::player) != None)
    {
        velocity = velocityAfterCollision(Game::player);
    }
    else if (collisionWithPaddle(Game::opponent) != None)
    {
        velocity = velocityAfterCollision(Game::opponent);
    }

    if (collisionWithWall(SCREEN_HEIGHT) != None)
    {
        velocity.y *= -1;
    }
}

bool Ball::updateScore()
{
    Direction out = outOfBounds(SCREEN_WIDTH);
    if (out == None)
    {
        return false;
    }

    switch (outOfBounds(SCREEN_WIDTH))
    {
    case Left:
        Game::addOpponentPoints(1);
        printf("P2 Point!\n");
        break;
    
    case Right:
        Game::addPlayerPoints(1);
        printf("P1 Point!\n");
        break;
    
    default:
        break;
    }

    return true;
}


void Ball::reset()
{
    //position = (Vec2<int>) {(SCREEN_WIDTH - static_cast<int>(size.x)) / 2, (SCREEN_HEIGHT - static_cast<int>(size.y)) / 2};
    position = default_position;
    velocity = (Vec2<int>) {0, 0};
}

void Ball::move(const Vec2<int> displacement)
{
    position.x += displacement.x;
    position.y += displacement.y;
}

void Ball::update()
{   
    if (!isFrozen())
    {   
        move(velocity);
    }

    handleCollision();
    if (updateScore())
    {
        outOfBoundsCallback();
    }
}

void Ball::render(const float interpolation)
{
    SDL_Rect rect = {position.x, position.y, static_cast<int>(size.x), static_cast<int>(size.y)};

    // printf("%i, %i\n", position.x, position.y);
    SDL_SetRenderDrawColor(Game::renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(Game::renderer, &rect);
}