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
    SDL_Window* window;
    SDL_Renderer* renderer;
    public:
    welcomeScreen();
    welcomeScreen(levelButton levelButt, changeColourButton B1, changeColourButton B2);
    void displayOptions();
    ~welcomeScreen();


};