// InputHandler.cpp - Source file for InputHandler class

#include "InputHandler.h"

std::unordered_map<SDL_KeyCode, bool> InputHandler::keyboard_state;

void InputHandler::init()
{
        keyboard_state[SDLK_ESCAPE] = false;
        keyboard_state[SDLK_SPACE] = false;
        keyboard_state[SDLK_RETURN] = false;
        keyboard_state[SDLK_1] = false;
        keyboard_state[SDLK_2] = false;
        keyboard_state[SDLK_w] = false;
        keyboard_state[SDLK_a] = false;
        keyboard_state[SDLK_s] = false;
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

    // Manually add useable keys because event.key.keysym.sym is SDL_Keycode but the actual keycodes are SDL_KeyCode...
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        keyboard_state[SDLK_ESCAPE] = key_active;
        break;

    case SDLK_SPACE:
        keyboard_state[SDLK_SPACE] = key_active;
        break;
    
    case SDLK_RETURN:
        keyboard_state[SDLK_RETURN] = key_active;
        break;

    case SDLK_1:
        keyboard_state[SDLK_1] = key_active;
        break;
    
    case SDLK_2:
        keyboard_state[SDLK_2] = key_active;
        break;

    case SDLK_w:
        keyboard_state[SDLK_w] = key_active;
        break;
    
    case SDLK_a:
        keyboard_state[SDLK_a] = key_active;
        break;
    
    case SDLK_s:
        keyboard_state[SDLK_s] = key_active;
        break;
    
    case SDLK_d:
        keyboard_state[SDLK_d] = key_active;
        break;
    
    case SDLK_UP:
        keyboard_state[SDLK_UP] = key_active;
        break;
    
    case SDLK_DOWN:
        keyboard_state[SDLK_DOWN] = key_active;
        break;
    
    case SDLK_LEFT:
        keyboard_state[SDLK_LEFT] = key_active;
        break;
    
    case SDLK_RIGHT:
        keyboard_state[SDLK_RIGHT] = key_active;
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