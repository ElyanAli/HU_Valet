#pragma once
#include <iostream>
#include "car.hpp"
#include "objects.hpp"
#include "coin.hpp"
#include "ParkingSpot.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>
#include <vector>
using namespace std;

class Car;
class Coin;
class ParkingSpot;

class CollisionManager{
    private:
        vector<vector<float>> getObstacleBoxCorners(Objects* obstacle);
        vector<vector<float>> getCarCoordinates(Car* car);
    public:
        bool checkCollisionObs( Car* car, Objects* object, vector<int>);
        // SDL_Rect calculate_rotated_bounding_box(Car* car);
        void resolveCollision(Car*, SDL_Rect);
        bool checkCollisionCoin(Car* car, Coin* coin);
        void resolveCoinCollision(Coin* thisCoin);
        bool checkParking( Car*, ParkingSpot*);
};
