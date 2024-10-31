// Game.cpp - Source file for Game class

#include "Game.h"

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <vector>

#include "InputHandler.h"

SDL_Renderer* Game::renderer = nullptr;
Vec2<uint8_t> Game::screen_size;

Paddle Game::player;
Paddle Game::opponent;
Ball Game::ball;

int Game::points_player;
int Game::points_opponent;

bool Game::init(const std::string title, const Vec2<int> position, const Vec2<int> size, const bool fullscreen)
{
    int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
    
    run_status = false;
    round_status = false;

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
    Game::screen_size = (Vec2<uint8_t>){static_cast<uint8_t>(display_mode.w), static_cast<uint8_t>(display_mode.h)};

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

    // Initialize input handler
    InputHandler::init();
    printf("Input handler initialized.\n");

    run_status = true;
    printf("Game initialized.\n");
    
    return true;
}

void Game::newGame()
{
    player.init(Player1, (Vec2<int>) {0, 250}, (Vec2<unsigned int>) {12, 100}, (Colour) {255, 255, 255});
    opponent.init(Player2, (Vec2<int>) {588, 250}, (Vec2<unsigned int>) {12, 100}, (Colour) {255, 255, 255});
    ball.init((Vec2<int>) {294, 0}, (Vec2<unsigned int>) {12, 12}, (Colour) {255, 255, 255});
    
    points_player = 0;
    points_opponent = 0;
    reset();
}

void Game::reset()
{
    ball.reset();

    round_status = false;
}

void Game::start()
{
    ball.setVelocity((Vec2<int>) {5, 5});
    round_status = true;
}

void Game::processInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            run_status = false;
        }

        InputHandler::processKeyboard(event);

        if (InputHandler::isActive(SDLK_ESCAPE))
        {
            run_status = false;
            round_status = false;
        }

        player.processInput(InputHandler::keyboard_state);      
        opponent.processInput(InputHandler::keyboard_state);

        if (round_status == false && player.getDirection() != None)
        {
            start();
        }
    }
}

void Game::update()
{
    player.update();
    opponent.update();
    if (ball.update())
    {
        reset();
    }
}

void Game::render(const float interpolation)
{
    // Clear screen/set background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render objects
    player.render(interpolation);
    opponent.render(interpolation);
    ball.render(interpolation);

    SDL_RenderPresent(renderer);
}

void Game::quit()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    printf("Game quit.\n");
}