// Paddle.cpp - Source file for Paddle class

#include "Paddle.h"

#include <SDL.h>

#include "Game.h"

Paddle::Paddle(const Vec2<int> position, const Vec2<int> size, const Colour colour)
{
    this->position = position;
    this->size = size;
    this->colour = colour;
}

Vec2<int> Paddle::getPosition()
{
    return position;
}

void Paddle::setPosition(const Vec2<int> position)
{
    this->position = position;
}

Vec2<int> Paddle::getSize()
{
    return size;
}

void Paddle::setSize(const Vec2<int> size)
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

void Paddle::render(const float interpolation)
{
    SDL_Rect rect = {position.x, position.y, size.x, size.y};

    SDL_SetRenderDrawColor(Game::renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(Game::renderer, &rect);
}