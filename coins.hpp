#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "objects.hpp"
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

class Coins : public Objects { //inherit from object
    private:
        // float acceleration;
        
        // const double acceleration = 3;
        // const double ANGLE_CHANGE = 5;
        // int fuel;
        // int collisionState;
        // double angle;
        // SDL_Point center;
        // double theta, delta;
        // const double DELTA_T = 1.0;
        // int velocity = 0;
        int imgState = 0;
        string path;
    public:
        
        Coins (SDL_Renderer* Rndr, string path, SDL_Rect sRect, SDL_Rect mRect);
        void drawCoin();
        // void accelerate();
        // void decelerate();
        // void turnLeft();
        // void turnRight();
        // void releaseAccelerate();
        // void releaseDeceleration();

};
