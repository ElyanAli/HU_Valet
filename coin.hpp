#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "objects.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "CollisionManager.hpp"
// #include <SDL.h>
// #include <SDL_image.h>
using namespace std;

class Coin : public Objects { //inherit from object
    private:
        int imgState = 0;
        string path = "./images/coins.png";
        int timerCount = 0;
        bool collected = false;
        void updateMoverRect(int);
    public:
        friend class CollisionManager;
        Coin(SDL_Renderer* Rndr, SDL_Rect mRect);
        void drawCoin();
        // void accelerate();
        // void decelerate();
        // void turnLeft();
        // void turnRight();
        // void releaseAccelerate();
        // void releaseDeceleration();

};
