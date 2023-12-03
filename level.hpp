#include <iostream>
#include <vector>
#include "objects.hpp"
#include "obstacles.hpp"
#include "coin.hpp"
#include "ParkingSpot.hpp"
#include "car.hpp"
using namespace std;

class Level{
    private:
        
        int levelNumber;
        ParkingSpot* parking;
        SDL_Renderer* renderer;
        string path;
        SDL_Texture* image;
        SDL_Texture* loadLevel();
    public:
        vector<Coin*> coins;
        vector<Obstacle *> obstacles;
        Car* playerCar = nullptr;
        Level(SDL_Renderer*, int, ParkingSpot*, string, string, SDL_Rect, SDL_Rect);
        void drawLevel();
        void insertCoin(SDL_Rect);
        void insertObstacle(string, SDL_Rect, SDL_Rect);
        ParkingSpot* getParking();

};