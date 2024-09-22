// main.cpp - Source file for main

#include <stdio.h>
#include <SDL.h>

#include <cstdint>

#include "Game.h"
#include "Paddle.h"
#include "Types.h"

Game* game = nullptr;

int main(int argc, char* args[])
{
    /* Paddle player((Vec2<int>) {5, 5}, (Vec2<int>) {75, 25});
    printf("X: %i\n", player.getPosition().x); */

    Uint64 next_tick = SDL_GetTicks64();
    int loops;
    float interpolation;

    game = new Game();
    game->init("Pong", (Vec2<int>) {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED}, (Vec2<int>) {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}, false);

    game->start();

    while (game->isRunning())
    {
        loops = 0;
        while (SDL_GetTicks64() > next_tick && loops < MAX_FRAME_SKIP)
        {
            game->processInput();
            game->update();

            next_tick += TICK_DELAY;
            loops++;
        }

        interpolation = float (SDL_GetTicks64() + TICK_DELAY - next_tick) / float (TICK_DELAY);
        game->render(interpolation);
    }

    game->quit();
    return 0;
}