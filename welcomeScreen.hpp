#pragma once
#include <iostream>
#include "levelButton.hpp"
#include "changeColourButton.hpp"
#include <SDL2/SDL.h>
using namespace std;

class welcomeScreen{
    private:
        levelButton *start = nullptr;
        changeColourButton button_1;
        changeColourButton button_2;
        string screenPath;
        SDL_Texture* loadImage(string);
    public:
        SDL_Window* window;
        SDL_Renderer* renderer;
        welcomeScreen();
        welcomeScreen(SDL_Renderer*);
        void displayScreen();
        // string displayMenu();
        ~welcomeScreen();
        SDL_Texture* startTexture = NULL;
        void displayButton();
        Mouse* mouse = nullptr;
        void update(bool);
        void drawMouse();


};