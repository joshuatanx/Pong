// Game.cpp - Source file for Game class

#include "Game.h"

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <vector>

SDL_Renderer* Game::renderer = nullptr;
Vec2<uint8_t> Game::screen_size;

Paddle Game::player((Vec2<int>) {0, 0}, (Vec2<int>) {100, 25}, (Colour) {255, 255, 255});

bool Game::init(const std::string title, const Vec2<int> position, const Vec2<int> size, const bool fullscreen)
{
    printf("%i\n", player.getPosition().x);
    int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
    run_status = false;

    if (fullscreen)
    {
        flags = flags | SDL_WINDOW_FULLSCREEN;
    }

    // attempt to initialize subsystems
    if (SDL_InitSubSystem(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL subsystems could not be initialized. SDL_ERROR: %s.\n", SDL_GetError());
        return false;
    }
    printf("Subsystems initialized.\n");

    // attempt to get display settings
    SDL_DisplayMode display_mode;
    if (SDL_GetCurrentDisplayMode(0, &display_mode) != 0)
    {
        printf("Could not retreive display mode. SDL_ERROR: %s.\n", SDL_GetError());
        return false;
    }
    printf("%i x %i\n", display_mode.w, display_mode.h);
    Game::screen_size = Vec2<uint8_t>{static_cast<uint8_t>(display_mode.w), static_cast<uint8_t>(display_mode.h)};

    // attempt to initialize window with given parameters
    window = SDL_CreateWindow(title.c_str(), position.x, position.y, size.x, size.y, flags);
    if (window == NULL)
    {
        printf("Window could not be initialized. SDL_ERROR: %s.\n", SDL_GetError());
        return false;
    }
    printf("Window initialized.\n");

    // attempt to initialize renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        printf("Renderer could not be initialized. SDL_ERROR: %s\n.", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    printf("Renderer initialized.\n");

    run_status = true;
    printf("Game initialized.\n");
    
    return true;
}

void Game::start()
{

}

void Game::processInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            run_status = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                run_status = false;
                break;

            default:
                break;
            }

        default:
            break;
        }

        // call input handler once i create the input handler
    }
}

void Game::update()
{

}

void Game::render(const float interpolation)
{
    //  Clear screen/set background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //  Render objects
    player.render(interpolation);

    SDL_RenderPresent(renderer);
}

void Game::quit()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    printf("Game quit.\n");
}