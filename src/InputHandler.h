// InputHandler.h - Header file for InputHandler class

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>
#include <unordered_map>

class InputHandler
{
public:
    static std::unordered_map<SDL_KeyCode, bool> keyboard_state;

    static void init();
    static void processKeyboard(const SDL_Event event);
    static bool isActive(const SDL_KeyCode key);
};

#endif