// Draw.cpp - source file for Draw class

#include "Draw.h"

#include <SDL.h>

#include "Game.h"

void Draw::line(const Vec2<int> head, const Vec2<int> tail, const Colour colour)
{

}

void Draw::rectangle(const int x, const int y, const int width, const int height, const Colour colour, const bool fill)
{
    SDL_Rect rect = (SDL_Rect) {x, y, width, height};
    SDL_SetRenderDrawBlendMode(Game::renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(Game::renderer, colour.r, colour.g, colour.b, colour.a);

    if (fill)
    {
        SDL_RenderFillRect(Game::renderer, &rect);
    }
    else
    {
        SDL_RenderDrawRect(Game::renderer, &rect);
    }
}

void Draw::rectangle(const Vec2<int> position, const Vec2<int> size, const Colour colour, const bool fill)
{
    rectangle(position.x, position.y, size.x, size.y, colour, fill);
}

void Draw::stripedRectangle(const int x, const int y, const int width, const int height, const Colour colour, const bool fill, const Direction stripe_direction, const int divisions, const int gap)
{
    if (stripe_direction == Left || stripe_direction == Right)
    {
        float length = (width - (gap * (divisions - 1))) / divisions;

        for (int i = 0; i < divisions - 1; i++)
        {
            rectangle(x + static_cast<int>((length + gap) * i), y, static_cast<int>(length), height, colour, fill);
        }

        rectangle(x + static_cast<int>((length + gap) * (divisions - 1)), y, width - x - static_cast<int>((length + gap) * (divisions - 1)), height, colour, fill);
    }
    else
    {
        float length = (height - (gap * (divisions - 1))) / divisions;
        
        for (int i = 0; i < divisions - 1; i++)
        {
            rectangle(x, y + static_cast<int>((length + gap) * i), width, static_cast<int>(length), colour, fill);
        }
        rectangle(x, y + static_cast<int>((length + gap) * (divisions - 1)), width, height - y - static_cast<int>((length + gap) * (divisions - 1)), colour, fill);
    }

    
}