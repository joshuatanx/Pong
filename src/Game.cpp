// Game.cpp - Source file for Game class

#include "Game.h"

#include <cstdint>
#include <math.h>
#include <memory>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdexcept>
#include <vector>

#include "Draw.h"
#include "InputHandler.h"
#include "TextureManager.h"

SDL_Renderer* Game::renderer = nullptr;
Vec2<uint8_t> Game::screen_size;

Interface Game::interface;

Paddle Game::player;
Paddle Game::opponent;
Ball Game::ball;
std::vector<Ball> Game::balls;

int Game::points_player;
int Game::points_opponent;
GameState Game::game_state;
GameMode Game::game_mode;

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

    // ball.setOutOfBoundsCallback([this]() {this->newRound();});
    game_state = SelectGameMode;

    run_status = true;
    round_status = false;
    printf("Game initialized.\n");
    
    return true;
}

void Game::newGame(const GameMode game_mode)
{
    printf("new game\n");
    player.init(Player1, (Vec2<int>) {0, 250}, (Vec2<unsigned int>) {12, 100}, (Colour) {255, 255, 255, 255});
    opponent.init(Player2, (Vec2<int>) {588, 250}, (Vec2<unsigned int>) {12, 100}, (Colour) {255, 255, 255, 255});
    balls.clear();

    switch (game_mode)
    {
    case Standard:
        balls.push_back(Ball());
        balls[balls.size() - 1].init((Vec2<int>) {294, 0}, (Vec2<unsigned int>) {12, 12}, (Colour) {255, 255, 255, 255}, (Vec2<int>) {static_cast<int>(SCREEN_WIDTH / 2) - 6, static_cast<int>(SCREEN_HEIGHT / 2) - 6});
        break;

    case Plus:
        balls.push_back(Ball());
        balls[balls.size() - 1].init((Vec2<int>) {294, 0}, (Vec2<unsigned int>) {12, 12}, (Colour) {255, 255, 255, 255}, (Vec2<int>) {static_cast<int>(SCREEN_WIDTH / 2) - 6, static_cast<int>(SCREEN_HEIGHT / 3) - 6});
        balls.push_back(Ball());
        balls[balls.size() - 1].init((Vec2<int>) {294, 50}, (Vec2<unsigned int>) {12, 12}, (Colour) {255, 255, 255, 255}, (Vec2<int>) {static_cast<int>(SCREEN_WIDTH / 2) - 6, static_cast<int>(SCREEN_HEIGHT / 3 * 2) - 6});
        break;

    case PlusPlus:
        balls.push_back(Ball());
        balls[balls.size() - 1].init((Vec2<int>) {294, 0}, (Vec2<unsigned int>) {12, 12}, (Colour) {255, 255, 255, 255}, (Vec2<int>) {static_cast<int>(SCREEN_WIDTH / 2) - 6, static_cast<int>(SCREEN_HEIGHT / 4) - 6});
        balls.push_back(Ball());
        balls[balls.size() - 1].init((Vec2<int>) {294, 50}, (Vec2<unsigned int>) {12, 12}, (Colour) {255, 255, 255, 255}, (Vec2<int>) {static_cast<int>(SCREEN_WIDTH / 2) - 6, static_cast<int>(SCREEN_HEIGHT / 4 * 2) - 6});
        balls.push_back(Ball());
        balls[balls.size() - 1].init((Vec2<int>) {294, 100}, (Vec2<unsigned int>) {12, 12}, (Colour) {255, 255, 255, 255}, (Vec2<int>) {static_cast<int>(SCREEN_WIDTH / 2) - 6, static_cast<int>(SCREEN_HEIGHT / 4 * 3) - 6});
    
    default:
        break;
    }

    for (int i = 0; i < balls.size(); i++)
    {
        balls[i].setOutOfBoundsCallback([this]() {this->newRound();});
    }
    
    points_player = 0;
    points_opponent = 0;
    newRound();
}

void Game::newRound()
{
    for (int i = 0; i < balls.size(); i++)
    {
        balls[i].reset();
    }

    round_status = false;
    game_state = Ready;
}

void Game::start()
{  
    for (int i = 0; i < balls.size(); i++)
    {
        int speed = balls[i].getSpeed() * std::pow(-1, i);
        balls[i].setVelocity((Vec2<int>) {speed, speed});
    }
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

void Game::pause()
{
    game_state = Paused;
    player.freeze();
    opponent.freeze();
    /* ball.freeze(); */
    /* for (Ball it : balls)
    {
        it.freeze();
    } */

    for (int i = 0; i < balls.size(); i++)
    {
        balls[i].freeze();
    }
}

void Game::resume()
{
    game_state = Playing;
    player.unfreeze();
    opponent.unfreeze();
    //ball.unfreeze();
    /* for (Ball it : balls)
    {
        it.unfreeze();
    } */
   for (int i = 0; i < balls.size(); i++)
    {
        balls[i].unfreeze();
    }
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

        switch (game_state)
        {
        case SelectGameMode:
            if (InputHandler::isActive(SDLK_1))
            {
                game_mode = Standard;
                newGame(game_mode);
            }
            else if (InputHandler::isActive(SDLK_2))
            {
                game_mode = Plus;
                newGame(game_mode);
            }
            else if (InputHandler::isActive(SDLK_3))
            {
                game_mode = PlusPlus;
                newGame(game_mode);
            }
            break;

        case Ready:
            if (InputHandler::isActive(SDLK_SPACE))
            {
                start();
            }
            break;

        case Playing:
            if (InputHandler::isActive(SDLK_ESCAPE))
            {
                pause();
            }
            player.processInput(InputHandler::keyboard_state);
            opponent.processInput(InputHandler::keyboard_state);
            break;

        case Paused:
            if (InputHandler::isActive(SDLK_ESCAPE))
            {
                resume();
            }
            break;

        case GameOver:
            // quit();
            break;

        default:
            break;
        }
    }
}

void Game::update()
{
    switch (game_state)
    {
    case Playing:
        player.update();
        opponent.update();
        for (int i = 0; i < balls.size(); i++)
        {
            balls[i].update();
        }
        break;

    default:
        break;
    }
}

void Game::render(const float interpolation)
{
    // Clear screen/set background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    switch (game_state)
    {
    case SelectGameMode:
        interface.render();
        break;

    case Ready:
        interface.render();
        player.render(interpolation);
        opponent.render(interpolation);
        for (int i = 0; i < balls.size(); i++)
        {
            balls[i].render(interpolation);
        }
        break;

    case Playing:
        player.render(interpolation);
        opponent.render(interpolation);
        for (int i = 0; i < balls.size(); i++)
        {
            balls[i].render(interpolation);
        }
        interface.render();
        break;
    
    case Paused:
        player.render(interpolation);
        opponent.render(interpolation);
        for (int i = 0; i < balls.size(); i++)
        {
            balls[i].render(interpolation);
        }
        interface.render();

    case GameOver:
        interface.render();

    default:
        break;
    }

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