#include <iostream>
#include <vector>
#include "objects.hpp"
#include "obstacles.hpp"
// #include "coins.hpp"
#include "parkingSpot.hpp"
using namespace std;

class Level{
    private:
        int levelNumber;
        vector<Obstacle *> obstacles;
        // vector<Coins> coins;
        parkingSpot* parking;
        SDL_Renderer* renderer;
        string path;
        SDL_Texture* image;
        SDL_Texture* loadLevel();
    public:
        Level(SDL_Renderer*, int, parkingSpot*, string);
        void loadObstacles();
        void drawLevel();
        // void loadCoins();
        void insertObstacle(SDL_Renderer* r, string pth, SDL_Rect rct, SDL_Rect mrct);

};