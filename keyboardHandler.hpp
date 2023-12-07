// #include "SDL2/SDL.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <unordered_map>
using namespace std;


class keyboardHandler {
    private:
        unordered_map<SDL_Keycode, SDL_EventType> currentKeyState;
        unordered_map<SDL_Keycode, SDL_EventType> prevKeyState;
    public:
        void handleKeyboardEvent(SDL_Event event) ;

        bool isPressed(SDL_Keycode keyCode);

        bool isReleasedNow(SDL_Keycode keyCode);
};
