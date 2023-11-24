#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "objects.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class Car : public Objects { //inherit from object
    private:
        // float acceleration;
        
        const double acceleration = 3;
        const double ANGLE_CHANGE = 5;
        int fuel;
        int collisionState;
        double angle;
        SDL_Point center;
        double theta, delta;
        const double DELTA_T = 1.0;
        int velocity = 0;

    public:
        
        Car (SDL_Renderer* Rndr, string path, SDL_Rect sRect, SDL_Rect mRect);
        void draw();
        void accelerate();
        void decelerate();
        void turnLeft();
        void turnRight();
        void releaseAccelerate();
        void releaseDeceleration();
        void straighten();

};
