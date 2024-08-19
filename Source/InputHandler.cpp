// InputHandler.cpp - Source file for InputHandler class

#include "InputHandler.h"

std::unordered_map<SDL_KeyCode, bool> InputHandler::keyboard_state;

void InputHandler::init()
{
        keyboard_state[SDLK_ESCAPE] = false;
        keyboard_state[SDLK_a] = false;
        keyboard_state[SDLK_d] = false;
}

void InputHandler::processKeyboard(SDL_Event event)
{
    bool key_active;
    if (event.type == SDL_KEYDOWN)
    {
        key_active = true;
    }
    else if (event.type == SDL_KEYUP)
    {
        key_active = false;
    }
    else
    {
        return;
    }

    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        keyboard_state[SDLK_ESCAPE] = key_active;
        break;
    
    case SDLK_a:
        keyboard_state[SDLK_a] = key_active;
        break;
    
    case SDLK_d:
        keyboard_state[SDLK_d] = key_active;
        break;
    
    default:
        break;
    }
}

bool InputHandler::isActive(const SDL_KeyCode key)
{
    if (keyboard_state.count(key) && keyboard_state.at(key))
    {
        return true;
    }
    return false;
}