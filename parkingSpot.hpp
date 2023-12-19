#pragma once
#include <iostream>
#include "objects.hpp"
#include "car.hpp"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;



class ParkingSpot:public Objects{
    private:
        bool parked;
        string path;
    public:
        ParkingSpot(SDL_Renderer*, SDL_Rect, SDL_Rect, string);

};

