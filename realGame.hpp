#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "car.hpp"
#include "level.hpp"
#include "welcomeScreen.hpp"
#include "keyboardHandler.hpp"
#include "CollisionManager.hpp"
#include "levelButton.hpp"
#include "obstacles.hpp"
#include "coin.hpp"
#include "mouse.hpp"

class realGame{
    private:
        int level = -1;
        SDL_Renderer* gRenderer = nullptr;
        vector<Level*> levels;
        welcomeScreen* wscreen = nullptr;
        keyboardHandler keyHandler;
        levelButton* done;
        Mouse* myMouse;
        bool levelComplete;
        void createLevel1();
        void createLevel2();
        void createLevel3();
        void updateCarPos();
        bool collided = false;
        CollisionManager cM;
    public:
        realGame(SDL_Renderer*);
        void drawCurrent();
        void updateCurrentState(SDL_Event&);
        void delay();
        // void drawItems();
};