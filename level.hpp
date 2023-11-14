#include <iostream>
#include <vector>
#include "objects.hpp"
#include "obstacles.hpp"
#include "coins.hpp"
#include "parkingSpot.hpp"
using namespace std;

class Level : public Objects{
    private:
        int levelNumber;
        vector<Obstacles> obstacles;
        vector<Coins> coins;
        parkingSpot parking_spot;
        SDL_Texture* image;
    public:
        void loadObstacles();
        void loadCoins();

};