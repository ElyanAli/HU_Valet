#include "keyboardHandler.hpp"
void keyboardHandler::handleKeyboardEvent(SDL_Event event) {
        SDL_Keycode thisKey = event.key.keysym.sym;
        prevKeyState[thisKey] = currentKeyState[thisKey];
        currentKeyState[thisKey] = static_cast<SDL_EventType>(event.type);
    }
bool keyboardHandler::isPressed(SDL_Keycode keyCode) {
        return (currentKeyState[keyCode] == SDL_KEYDOWN);
    }
bool keyboardHandler::isReleasedNow(SDL_Keycode keyCode) {
        return (prevKeyState[keyCode] == SDL_KEYDOWN & currentKeyState[keyCode] == SDL_KEYUP);
    }

