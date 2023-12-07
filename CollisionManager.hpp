#pragma once
#include <iostream>
#include "car.hpp"
#include "objects.hpp"
#include "obstacles.hpp"
#include "coin.hpp"
#include "ParkingSpot.hpp"
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// #include <SDL2/SDL_main.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_main.h>
#include <vector>
#include <algorithm>
using namespace std;

class Car;
class Coin;
class ParkingSpot;

class CollisionManager{
    private:
        pair<float, float> projectObjectOnAxis(Objects* obj, pair<float, float> axis);
        bool overlap(pair<float, float> interval1, pair<float, float> interval2);
        vector<vector<float>> getVertices(Objects* obj);
        vector<vector<float>> getCarVertices(Objects* obj);
        vector<vector<float>> getObstacleVertices(Objects* obj);

    public:
        bool checkCollisionObs( Car* car, Objects* object);
        bool checkCollisionCoin(Car* car, Coin* coin);
        void resolveCoinCollision(Coin* thisCoin);
        bool checkParking( Car*, ParkingSpot*);
        void resolveCollision(Car*, SDL_Rect);

        
};





