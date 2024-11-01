// Game.cpp - Source file for Game class

#include "Game.h"

#include <cstdint>
#include <memory>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdexcept>
#include <vector>

#include "InputHandler.h"
#include "TextureManager.h"

SDL_Renderer* Game::renderer = nullptr;
Vec2<uint8_t> Game::screen_size;

Interface Game::interface;

Paddle Game::player;
Paddle Game::opponent;
Ball Game::ball;

int Game::points_player;
int Game::points_opponent;
GameState Game::game_state;

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
        printf("Renderer could not be initialized. SDL_ERROR: %s.\n", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    printf("Renderer initialized.\n");

    // Initialize input handler
    InputHandler::init();
    printf("Input handler initialized.\n");

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not be initialized. SDL_image Error: %s.\n", IMG_GetError());
        return false;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not be initialized. SDL_ttf Error: %s.\n", TTF_GetError());
        return false;
    }

    TextureManager::loadFontStyle("assets/fonts/Vogue.ttf", "Vogue", 16, (SDL_Colour) {255, 255, 255});
    printf("Font initialized.\n");

    ball.setOutOfBoundsCallback([this]() {this->newRound();});
    game_state = StartScreen;

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
    newRound();
}

void Game::newRound()
{
    ball.reset();

    round_status = false;
}

void Game::start()
{
    ball.setVelocity((Vec2<int>) {5, 5});
    round_status = true;
    game_state = Playing;
}

int Game::getPlayerPoints()
{
    return points_player;
}

int Game::getOpponentPoints()
{
    return points_opponent;
}

void Game::setPlayerPoints(const int points)
{
    points_player = points;
}

void Game::setOpponentPoints(const int points)
{
    points_opponent = points;
}

void Game::addPlayerPoints(const int points)
{
    points_player += points;
}

void Game::addOpponentPoints(const int points)
{
    points_opponent += points;
}

GameState Game::getGameState()
{
    return game_state;
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
    ball.update();
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
    interface.render();

    SDL_RenderPresent(renderer);
}

void Game::quit()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    TextureManager::quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    printf("Game quit.\n");
}