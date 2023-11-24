#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "objects.hpp"
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

class Car : public Objects { //inherit from object
    private:
        // float acceleration;
        
        const double SPEED = 5.0;
        const double ANGLE_CHANGE = 5;
        int fuel;
        int collisionState;
        double angle;
        SDL_Point center;
        double theta, delta;
        const double DELTA_T = 1.0;


        // SDL_Point axis = {13/2, 10};
        // int steering;
        // float speed;
        // float angle;
        // float acceleration = 5;
        // float max_speed = 10;

    

        // SDL_Rect moverRect;
        // const float dT;
        // double frontDistance;
        // double rearDistance;
        // double slip;
        // double acceleration_input;
        // double steerAngle_input;
    public:
        // void moveFront();
        // void moveBack();
        // void moveRight(bool direction);
        // void moveLeft(bool direction);
        // void upState();
        Car (SDL_Renderer* Rndr, string path, SDL_Rect sRect, SDL_Rect mRect);
        void draw();
        // void accelerate(int direction);
        // void turn(int s);
        // SDL_Point getAxis();
        // float getAngle();

        // void update(double v, double phi);
        void accelerate();
        void deaccelerate();
        void turnLeft();
        void turnRight();
        void releaseAccelerate();
        void releaseBreak();
        void straighten();

};
