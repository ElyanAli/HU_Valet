#pragma once
#include <iostream>
#include "car.hpp"
#include "objects.hpp"
#include "obstacles.hpp"
#include "coin.hpp"
#include "ParkingSpot.hpp"
#include "score.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>
#include <vector>
using namespace std;


class Car;
class Coin;
class ParkingSpot;
class Score;

class CollisionManager{
    private:
        pair<float, float> projectObjectOnAxis(Objects* obj, pair<float, float> axis);
        bool overlap(pair<float, float> interval1, pair<float, float> interval2);
        vector<vector<float>> getVertices(Objects* obj);
        vector<vector<float>> getCarVertices(Objects* obj);
        vector<vector<float>> getObstacleVertices(Objects* obj);
        int collisionTimer = 0;

    public:
        bool checkCollisionBnd(Car*, vector<int>);
        bool checkCollisionObs( Car*, Objects*);
        bool checkCollisionCoin(Car* , Coin* );
        void resolveCoinCollision(Coin* );
        bool checkParking( Car*, ParkingSpot*);
        void resolveCollision(Car*);
        void revive(Car*);
};





