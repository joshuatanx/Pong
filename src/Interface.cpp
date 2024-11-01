// Interface.cpp - source file for Interface class

#include "Interface.h"

#include <string>

#include "Game.h"
#include "TextureManager.h"

void Interface::init()
{

}

void Interface::update()
{
    
}

void Interface::drawStartScreen()
{
    TextureManager::renderText("Press Space to start.", (SDL_Rect) {SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 + 100, 400, 24});
}

void Interface::drawScore(const int player_score, const int opponent_score)
{
    TextureManager::renderText(std::to_string(player_score), (SDL_Rect) {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 10, 50, 75});
    TextureManager::renderText(std::to_string(opponent_score), (SDL_Rect) {(SCREEN_WIDTH / 4) * 3 - 50, SCREEN_HEIGHT / 10, 50, 75});
}

void Interface::drawPauseScreen()
{
    drawScore(Game::getPlayerPoints(), Game::getOpponentPoints());
    TextureManager::renderText("Press Escape to resume.", (SDL_Rect) {SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 + 100, 400, 24});
}

void Interface::drawGameOverScreen(const int player_score, const int opponent_score)
{

}

void Interface::render()
{
    switch (Game::getGameState())
    {
    case StartScreen:
        drawStartScreen();
        break;
    
    case Playing:
        drawScore(Game::getPlayerPoints(), Game::getOpponentPoints());
        break;

    case Paused:
        drawPauseScreen();
        break;
    
    case GameOver:
        drawGameOverScreen(Game::getPlayerPoints(), Game::getOpponentPoints());
        break;

    default:
        break;
    }
}