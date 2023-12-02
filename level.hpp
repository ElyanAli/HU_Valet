#include <iostream>
#include <vector>
#include "objects.hpp"
#include "obstacles.hpp"
// #include "coins.hpp"
#include "parkingSpot.hpp"
#include "car.hpp"
using namespace std;

class Level{
    private:
        
        int levelNumber;
        // vector<Coins> coins;
        parkingSpot* parking;
        SDL_Renderer* renderer;
        string path;
        SDL_Texture* image;
        SDL_Texture* loadLevel();
    public:
        vector<Obstacle *> obstacles;
        Car* playerCar = nullptr;
        Level(SDL_Renderer*, int, parkingSpot*, string, string, SDL_Rect, SDL_Rect);
        void loadObstacles();
        void drawLevel();
        // void loadCoins();
        void insertObstacle(SDL_Renderer* r, string pth, SDL_Rect rct, SDL_Rect mrct);

};