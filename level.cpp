#include "level.hpp"


Level::Level(SDL_Renderer* r, int level, parkingSpot* pSpot, string imagePath){
    path = imagePath;
    parking = pSpot;
    levelNumber = level;
    renderer = r;
};

void Level::loadObstacles(){
    for(int i = 0; i < obstacles.size(); i++){
        obstacles[i].loadObstacle();
    }
}

// void Level::loadCoins(){
//     for(int i = 0; i < coins.size(); i++){
//         coins[i].loadCoin();
//     }
// }

void Level::insertObstacle(SDL_Renderer* r, string pth, SDL_Rect rct, SDL_Rect mrct){
    obstacles.push_back(Obstacle(r, pth, rct, mrct));
}

void Level::loadLevel(){
    // load the image of the level
    SDL_Surface *imageSurface = SDL_LoadBMP(path.c_str());
    image = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    SDL_RenderCopy(renderer, image, NULL, NULL);
    SDL_RenderPresent(renderer);

    // load the obstacles
    loadObstacles();
    // load the coins
    
    // loadCoins()
    
}

