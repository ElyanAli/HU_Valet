#pragma once
#include <iostream>
#include <vector>
#include "objects.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <SDL.h>
// #include <SDL_image.h>
using namespace std;

class Digits : public Objects { //inherit from object
    private:
        // int imgState = 0;
        string path = "images/digits.png";
        vector<SDL_Rect> digitSRect = {
                                        {918, 0, 69, 82}, //0
                                        {13, 1, 35, 81},   //1
                                        {90, 0, 64, 82},  //2
                                        {188, 1, 65, 81},  //3
                                        {291, 1, 74, 81}, //4
                                        {399, 1, 64, 81}, //5
                                        {501, 0, 66, 82}, //6
                                        {603, 1, 65, 81}, //7
                                        {706, 0, 68, 82}, //8
                                        {812, 0, 66, 82}  //9
        };
        int count = 0;
        SDL_Rect getMover(int, int);
        SDL_Rect getMover(int, int, int, int);
    public:
        Digits(SDL_Renderer* Rndr);
        void drawDigit(int digit, int posX, int posY);
        void drawDigit(int digit, int posX, int posY, int w, int h);
        void drawDigit(int digit, int posX, int posY, int angle);

};
