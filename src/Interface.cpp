// Interface.cpp - source file for Interface class

#include "Interface.h"

#include <string>

#include "Draw.h"
#include "Game.h"
#include "TextureManager.h"

void Interface::init()
{

}

void Interface::update()
{
    
}

void Interface::drawGameModeScreen()
{
    TextureManager::renderText("Pong++", (SDL_Rect) {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 8, 200, 64});
    TextureManager::renderText("Game mode select:", (SDL_Rect) {SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 25, 300, 36});
    TextureManager::renderText("1) Standard", (SDL_Rect) {SCREEN_WIDTH / 2 - 125, SCREEN_HEIGHT / 2 + 100, 250, 36});
    TextureManager::renderText("2) Pong+", (SDL_Rect) {SCREEN_WIDTH / 2 - 125, SCREEN_HEIGHT / 2 + 150, 250, 36});
    TextureManager::renderText("3) Pong++", (SDL_Rect) {SCREEN_WIDTH / 2 - 125, SCREEN_HEIGHT / 2 + 200, 250, 36});
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

void Interface::drawNet()
{
    Draw::stripedRectangle(SCREEN_WIDTH / 2 - 3, 0, 6, SCREEN_HEIGHT, (Colour) {255, 255, 255, 100}, true, Up, 10, 25);
}

void Interface::drawPauseScreen()
{
    drawScore(Game::getPlayerPoints(), Game::getOpponentPoints());
    // Draw::stripedRectangle(SCREEN_WIDTH / 2 - 3, 0, 6, SCREEN_HEIGHT, (Colour) {255, 255, 255, 100}, true, Up, 10, 25);
    TextureManager::renderText("Press Escape to resume.", (SDL_Rect) {SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 + 100, 400, 24});
}

void Interface::drawGameOverScreen(const int player_score, const int opponent_score)
{

}

void Interface::render()
{
    switch (Game::getGameState())
    {
    case SelectGameMode:
        drawGameModeScreen();
        break;

    case Ready:
        drawStartScreen();
        drawScore(Game::getPlayerPoints(), Game::getOpponentPoints());
        drawNet();
        break;
    
    case Playing:
        drawScore(Game::getPlayerPoints(), Game::getOpponentPoints());
        drawNet();
        break;

    case Paused:
        drawPauseScreen();
        drawNet();
        break;
    
    case GameOver:
        drawGameOverScreen(Game::getPlayerPoints(), Game::getOpponentPoints());
        break;

    default:
        break;
    }
}