#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "objects.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "CollisionManager.hpp"
using namespace std;

class Car : public Objects { //inherit from object
    private:
        // float acceleration;
        
        const int acceleration = 3;
        const int ANGLE_CHANGE = 5;
        int fuel;
        int collisionState;
        int angle;
        SDL_Point center;
        double theta, delta;
        const double DELTA_T = 1.0;
        int velocity = 0;
        void setAngle();
        void moveCar();
    public:
        
        Car (SDL_Renderer* Rndr, string path, SDL_Rect sRect, SDL_Rect mRect);
        void draw();
        void accelerate();
        void decelerate();
        void turnLeft();
        void turnRight();
        void releaseAccelerate();
        void releaseDeceleration();
        int getAngle() const;
        void hardSetCarPos(float);
        friend class CollisionManager;
        

};
