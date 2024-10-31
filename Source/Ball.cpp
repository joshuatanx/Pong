// Ball.cpp - Source file for Ball class

#include "Ball.h"

#include <SDL.h>

#include "Game.h"

void Ball::init(const Vec2<int> position, const Vec2<unsigned int> size, const Colour colour)
{
    this->position = position;
    this->size = size;
    this->colour = colour;
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

Vec2<int> Ball::getVelocity()
{
    return velocity;
}

void Ball::setVelocity(const Vec2<int> velocity)
{
    this->velocity = velocity;
}

void Ball::setOutOfBoundsCallback(std::function<void()> callback)
{
    outOfBoundsCallback = callback;
    std::cout << "Set out of bounds callback";
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
    if (collisionWithPaddle(Game::player) != None || collisionWithPaddle(Game::opponent) != None)
    {
        velocity.x *= -1;
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
        Game::points_opponent++;
        printf("P2 Point!");
        break;
    
    case Right:
        Game::points_player++;
        printf("P1 Point!");
        break;
    
    default:
        break;
    }

    return true;
}


void Ball::reset()
{
    position = (Vec2<int>) {(SCREEN_WIDTH - static_cast<int>(size.x)) / 2, (SCREEN_HEIGHT - static_cast<int>(size.y)) / 2};
    velocity = (Vec2<int>) {0, 0};
}

void Ball::move(const Vec2<int> displacement)
{
    position.x += displacement.x;
    position.y += displacement.y;
}

void Ball::update()
{
    move(velocity);
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