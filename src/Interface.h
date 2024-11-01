// Interface.h - header file for Interface class

#ifndef INTERFACE_H
#define INTERFACE_H

#include <SDL.h>
#include <unordered_map>
#include <vector>

#include "Types.h"

class Interface
{
public:
    void init();
    void update();

    void drawStartScreen();
    void drawScore(const int player_score, const int opponent_score);
    void drawPauseScreen();
    void drawGameOverScreen(const int player_score, const int opponent_score);

    void render();

private:

};

#endif