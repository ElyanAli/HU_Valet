#pragma once
#include <iostream>
#include "car.hpp"
#include "objects.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>
#include <vector>
using namespace std;

class CollisionManager{
    public:
        bool checkCollision( Car* car, Objects* object);
        SDL_Rect calculate_rotated_bounding_box(Car* car);
        vector<SDL_Point> getCarCoordinates(Car* car);
};
