#pragma once
#include <iostream>
#include <vector>
#include "objects.hpp"
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

class Digits : public Objects { //inherit from object
    private:
        // int imgState = 0;
        string path = "images/digits.png";
        vector<SDL_Rect> digitSRect = {
                                        {392, 0, 30, 35}, //0
                                        {5, 0, 16, 35},   //1
                                        {38, 0, 28, 35},  //2
                                        {80, 0, 28, 35},  //3
                                        {124, 0, 32, 35}, //4
                                        {170, 0, 28, 35}, //5
                                        {214, 0, 28, 35}, //6
                                        {257, 0, 28, 35}, //7
                                        {301, 0, 30, 35}, //8
                                        {347, 0, 28, 35}  //9
        };
        int count = 0;
        // int timerCount = 0;
        // bool collected = false;
        // void updateMoverRect(int);
    public:
        // friend class CollisionManager;
        Digits(SDL_Renderer* Rndr, SDL_Rect mRect);
        void drawDigits();
        void incDigit(int, int, int);
        // void accelerate();
        // void decelerate();
        // void turnLeft();
        // void turnRight();
        // void releaseAccelerate();
        // void releaseDeceleration();

};
