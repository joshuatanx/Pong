// Paddle.cpp - Source file for Paddle class

#include "Paddle.h"

#include <SDL.h>

#include "Game.h"
#include "InputHandler.h"

Paddle::Paddle(const PaddleType paddle_type, const Vec2<int> position, const Vec2<unsigned int> size, const Colour colour, const unsigned int speed)
{
    this->paddle_type = paddle_type;
    this->position = position;
    this->size = size;
    this->colour = colour;
    direction = None;
    is_frozen = false;
}

void Paddle::init(const PaddleType paddle_type, const Vec2<int> position, const Vec2<unsigned int> size, const Colour colour, const unsigned int speed)
{
    this->paddle_type = paddle_type;
    this->position = position;
    this->size = size;
    this->colour = colour;
    this->speed = speed;
    direction = None;
    is_frozen = false;
}

PaddleType Paddle::getPaddleType()
{
    return paddle_type;
}

void Paddle::setPaddleType(const PaddleType paddle_type)
{
    this->paddle_type = paddle_type;
}

Vec2<int> Paddle::getPosition()
{
    return position;
}

void Paddle::setPosition(const Vec2<int> position)
{
    this->position = position;
}

unsigned int Paddle::getSpeed()
{
    return speed;
}

void Paddle::setSpeed(const unsigned int speed)
{
    this->speed = speed;
}

Vec2<unsigned int> Paddle::getSize()
{
    return size;
}

void Paddle::setSize(const Vec2<unsigned int> size)
{
    this->size = size;
}

Colour Paddle::getColour()
{
    return colour;
}

void Paddle::setColour(const Colour colour)
{
    this->colour = colour;
}

Direction Paddle::getDirection()
{
    return direction;
}

void Paddle::setDirection(const Direction direction)
{
    this->direction = direction;
}

bool Paddle::isFrozen()
{
    return is_frozen;
}

void Paddle::freeze()
{
    is_frozen = true;
}

void Paddle::unfreeze()
{
    is_frozen = false;
}

void Paddle::move(const Vec2<int> displacement)
{
    position.x += displacement.x;
    position.y += displacement.y;
}


void Paddle::processInput(const std::unordered_map<SDL_KeyCode, bool> keyboard_state)
{
    SDL_KeyCode up_key, down_key;
    switch (paddle_type)
    {
    case Player1:
        up_key = SDLK_w;
        down_key = SDLK_s;
        break;
    
    case Player2:
        up_key = SDLK_UP;
        down_key = SDLK_DOWN;
        break;
    
    default:
        return;
    }

    if (InputHandler::isActive(up_key) && !InputHandler::isActive(down_key))
    {
        direction = Up;
    }
    else if (InputHandler::isActive(down_key) && !InputHandler::isActive(up_key))
    {
        direction = Down;
    }
    else
    {
        direction = None;
    }
}

void Paddle::update()
{   
    if (isFrozen())
    {
        return;
    }

    switch (direction)
    {
    case Up:
        move((Vec2<int>) {0, -1 * static_cast<int>(speed)});
        break;

    case Down:
        move((Vec2<int>) {0, static_cast<int>(speed)});
        break;
    
    default:
        break;
    }
}

void Paddle::render(const float interpolation)
{
    SDL_Rect rect = {position.x, position.y, static_cast<int>(size.x), static_cast<int>(size.y)};

    // printf("%i, %i\n", position.x, position.y);
    SDL_SetRenderDrawColor(Game::renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(Game::renderer, &rect);
}