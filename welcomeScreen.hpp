#pragma once
#include <iostream>
#include "button.hpp"
#include <SDL2/SDL.h>
using namespace std;

class welcomeScreen{
    private:
        button *start = nullptr;
        string screenPath;
        SDL_Texture* loadImage(string);
        SDL_Texture* startTexture = NULL;
        SDL_Renderer* renderer;
        Mouse* mouse = nullptr;
    public:
        welcomeScreen();
        welcomeScreen(SDL_Renderer*);
        void displayScreen();
        void displayButton();
        bool update(bool);
        void drawMouse();
        ~welcomeScreen();
};