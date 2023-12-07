#pragma once
// #include <SDL2/SDL.h> //for Meesum
// #include <SDL2/SDL_image.h> //For Meesum
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
// #include "car.hpp"
#include <unordered_set>
// #include "keyboardHandler.hpp"
#include "realGame.hpp"


class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;
    realGame* parkingGame = nullptr;
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;
    //The window renderer
    SDL_Renderer* gRenderer = NULL;
    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    SDL_Texture* assets=NULL;
    // keyboardHandler keyHandler;

public:
    // Car* playerCar = nullptr;
    Game();
    bool init();
    // bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
    // void updateCarPos();
};
