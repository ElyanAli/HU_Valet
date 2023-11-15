#pragma once
#include <iostream>
#include "objects.hpp"
using namespace std;

class Car : public Objects { //inherit from object
    private:
        float acceleration;
        float speed;
        int fuel;
        int collisionState;
        SDL_Rect moverRect;
    public:
        // void moveFront();
        // void moveBack();
        // void moveRight(bool direction);
        // void moveLeft(bool direction);
        // void upState();
        Car (SDL_Renderer* Rndr, SDL_Rect rect);
        void accelerate();
        void deaccelerate();
        void turnLeft();
        void turnRight();
        void releaseAccelerate();
        void releaseBreak();
        void straighten();

};
