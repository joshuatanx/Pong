// Ball.cpp - Source file for Ball class

#include "Ball.h"

#include <SDL.h>

#include "Game.h"

void Ball::init(const Vec2<int> position, const Vec2<unsigned int> size, const Colour colour)
{
    this->position = position;
    this->size = size;
    this->colour = colour;
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

Vec2<int> Ball::getDirection()
{
    return direction;
}

void Ball::setDirection(const Vec2<int> direction)
{
    this->direction = direction;
}

void Ball::move(const Vec2<int> displacement)
{
    position.x += displacement.x;
    position.y += displacement.y;
}

void Ball::update()
{
    move(direction);
}

void Ball::render(const float interpolation)
{
    SDL_Rect rect = {position.x, position.y, static_cast<int>(size.x), static_cast<int>(size.y)};

    printf("%i, %i\n", position.x, position.y);
    SDL_SetRenderDrawColor(Game::renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(Game::renderer, &rect);
}