#pragma once
#include <iostream>
#include "welcomeScreen.hpp"
#include <SDL.h>


// #include "levelButton.hpp"

// #include "changeColourButton.hpp"
using namespace std;

welcomeScreen::welcomeScreen(){}
welcomeScreen::welcomeScreen( SDL_Renderer* r)
    : renderer(r){}

    string welcomeScreen::displayScreen()
    {
        return "./images/welcome3.png";
        

    }

    //destructor
    welcomeScreen::~welcomeScreen() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    
