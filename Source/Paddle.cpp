// Paddle.cpp - Source file for Paddle class

#include "Paddle.h"

#include <SDL.h>

#include "Game.h"
#include "InputHandler.h"

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

Direction Paddle::getDirection()
{
    return direction;
}

void Paddle::setDirection(const Direction direction)
{
    this->direction = direction;
}


void Paddle::processInput(const std::unordered_map<SDL_KeyCode, bool> keyboard_state)
{
    if (InputHandler::isActive(SDLK_a) && !InputHandler::isActive(SDLK_d))
    {
        direction = Left;
        printf("left\n");
    }
    else if (InputHandler::isActive(SDLK_d) && !InputHandler::isActive(SDLK_a))
    {
        direction = Right;
        printf("right\n");
    }
    else
    {
        direction = None;
    }
}

void Paddle::render(const float interpolation)
{
    SDL_Rect rect = {position.x, position.y, size.x, size.y};

    SDL_SetRenderDrawColor(Game::renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(Game::renderer, &rect);
}