#pragma once
#include <iostream>
#include "levelButton.hpp"
#include "changeColourButton.hpp"
#include <SDL.h>
using namespace std;

class welcomeScreen{
    private:
    levelButton level_buttons;
    changeColourButton button_1;
    changeColourButton button_2;
    public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    welcomeScreen();
    welcomeScreen(SDL_Renderer*);
    string displayScreen();
    ~welcomeScreen();


};