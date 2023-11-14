#include <iostream>
#include <vector>
#include "obstacles.hpp"
#include "coins.hpp"
#include "parkingSpot.hpp"
using namespace std;

class Level{
    private:
    int levelNumber;
    vector<Obstacles> obstacles;
    vector<Coins> coins;
    parkingSpot parking_spot;
    SDL_Texture* image;

};