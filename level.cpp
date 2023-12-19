#include "level.hpp"

Level::Level(SDL_Renderer* r, int level, ParkingSpot* pSpot, string levelPath, string carPath, SDL_Rect carSrc, SDL_Rect carMover){
    path = levelPath;
    parking = new ParkingSpot(*pSpot);
    levelNumber = level;
    renderer = r;
    image = loadLevel();
    playerCar = new Car(renderer, carPath, carSrc, carMover);
};

void Level::insertObstacle(string pth, SDL_Rect rct, SDL_Rect mrct){
    Obstacle* thisObstacle = new Obstacle(renderer, pth, rct, mrct);
    obstacles.push_back(thisObstacle);
}

void Level::insertCoin(SDL_Rect mrct){
    Coin* thisCoin = new Coin(renderer, mrct);
    coins.push_back(thisCoin);
}

void Level::drawLevel(){
    SDL_RenderCopy(renderer, image, NULL, NULL);
    parking->draw();
    for(int i = 0;  i < obstacles.size(); i++){
        obstacles[i]->draw();
    }
    for(int i = 0; i < coins.size(); i++){
        coins[i]->draw();
    }
    playerCar->draw();
}

SDL_Texture* Level::loadLevel(){
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

ParkingSpot* Level::getParking(){
    return parking;
};

bool Level::isComplete(){
    int totalCollected = 0;
    for (auto coin: coins){
        if (coin->isCollected()){
            totalCollected++;
        }
    }
    if (totalCollected>= coins.size()*0.7){
        return true;
    }
    return false;
}

Level::~Level(){
    for (auto obstacle: obstacles){
            delete obstacle;
        }
        for (auto coin: coins){
            delete coin;
        }
        delete playerCar;
};