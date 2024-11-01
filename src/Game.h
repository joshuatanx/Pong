// Game.h - Header file for Game class

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <string>
#include <vector>

#include "Ball.h"
#include "Interface.h"
#include "Paddle.h"
#include "Types.h"

class Game
{
public:
    bool init(const std::string title, const Vec2<int> position, const Vec2<int> size, const bool fullscreen = false);

    void newGame();
    void newRound();
    void start();

    static int getPlayerPoints();
    static int getOpponentPoints();
    static void setPlayerPoints(const int points);
    static void setOpponentPoints(const int points);
    static void addPlayerPoints(const int points);
    static void addOpponentPoints(const int points);

    static GameState getGameState();

    static void pause();
    static void resume();

    void processInput();
    void update();
    void render(const float interpolation);
    void quit();

    bool isRunning()
    {
        return run_status;
    }

    void startRound()
    {
        round_status = true;
        game_state = Playing;
    }

    void endRound()
    {
        round_status = false;
    }

    bool roundHasStarted()
    {
        return round_status;
    }

    static SDL_Renderer* renderer;
    static Vec2<uint8_t> screen_size;
    static Vec2<uint8_t> window_size;

    static Interface interface;

    static std::vector<Paddle> paddles;
    static Paddle player;
    static Paddle opponent;
    static Ball ball;

private:
    static int points_player;
    static int points_opponent;
    static GameState game_state;
    bool run_status;
    bool round_status;
    SDL_Window* window;
};

#endif // GAME_H