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
#include "button.hpp"
#include "obstacles.hpp"
#include "coin.hpp"
#include "mouse.hpp"
#include "score.hpp"
#include "digits.hpp"

class realGame{
    private:
        int level = -1;
        SDL_Renderer* gRenderer = nullptr;
        vector<Level*> levels;
        vector<int> levelBoundaries;
        welcomeScreen* wscreen = nullptr;
        keyboardHandler keyHandler;
        button* done;
        button* revive;
        button* backToHome;
        Mouse* myMouse;
        Score* scorer;
        CollisionManager cM;
        bool levelComplete= false;
        void createLevel1();
        void createLevel2();
        void updateCarPos();
        bool gameOver= false;
        bool revived= false;
        bool reviveButtonEnabled= false;
        SDL_Texture* gameOverText;
        SDL_Texture* reviveText;
        SDL_Texture* loadImage(string);
        int coinsReqForRevival;
        int incReqCoinsBy;
        Digits digitDisplay;
    public:
        realGame(SDL_Renderer*);
        void drawCurrent();
        void updateCurrentState(SDL_Event&);
        void delay();
        void displayNumber(int, int, int);
        void displayNumber(int, int, int, int);
};