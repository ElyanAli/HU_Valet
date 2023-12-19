#include "SDL2/SDL.h"
#include <iostream>
#include <unordered_map>
using namespace std;


class keyboardHandler {
    private:
        unordered_map<SDL_Keycode, SDL_EventType> currentKeyState;
        unordered_map<SDL_Keycode, SDL_EventType> prevKeyState;
    public:
        void handleKeyboardEvent(SDL_Event event) ;

        bool isPressed(SDL_KeyCode keyCode);

        bool isReleasedNow(SDL_KeyCode keyCode);
        
        void clearAll();
        ~keyboardHandler();
};
