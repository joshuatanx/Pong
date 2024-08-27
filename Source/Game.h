// Game.h - Header file for Game class

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <string>
#include <vector>

#include "Ball.h"
#include "Paddle.h"
#include "Types.h"

class Game
{
public:
    bool init(const std::string title, const Vec2<int> position, const Vec2<int> size, const bool fullscreen = false);

    void start();

    void processInput();
    void update();
    void render(const float interpolation);
    void quit();

    bool isRunning()
    {
        return run_status;
    }

    static SDL_Renderer* renderer;
    static Vec2<uint8_t> screen_size;
    static Vec2<uint8_t> window_size;

    static Paddle player;
    static Paddle enemy;
    static Ball ball;

private:
    bool run_status;
    SDL_Window* window;
};

#endif // GAME_H