#include "level.hpp"

Level::Level(SDL_Renderer* r, int level, ParkingSpot* pSpot, string levelPath, string carPath, SDL_Rect carSrc, SDL_Rect carMover){
    path = levelPath;
    parking = new ParkingSpot(*pSpot);
    levelNumber = level;
    renderer = r;
    image = loadLevel();
    playerCar = new Car(renderer, carPath, carSrc, carMover);

};
// void Level::loadCoins(){
//     for(int i = 0; i < coins.size(); i++){
//         coins[i].loadCoin();
//     }
// }
void Level::insertObstacle(string pth, SDL_Rect rct, SDL_Rect mrct){
    Obstacle* thisObstacle = new Obstacle(renderer, pth, rct, mrct);
    obstacles.push_back(thisObstacle);
}
void Level::insertCoin(SDL_Rect mrct){
    Coin* thisCoin = new Coin(renderer, mrct);
    coins.push_back(thisCoin);
}

//
// void Level::insertScore(SDL_Rect mrct) {
//     Digits* thisDigit = new Digits(renderer, mrct);
//     score.push_back(thisDigit);
// }

// void Level::incScore() {
//     // cout<<"No error here?";
//     score[0]->incDigit();
// } //

void Level::drawLevel(){
    SDL_RenderCopy(renderer, image, NULL, NULL);
    parking->draw();
    for(int i = 0;  i < obstacles.size(); i++){
        obstacles[i]->drawObstacle();
    }
    for(int i = 0; i < coins.size(); i++){
        coins[i]->drawCoin();
    }
    playerCar->draw();
    // for (int i = 0; i < score.size(); i++) {
    //     score[i]->drawDigits();
    // }
}

SDL_Texture* Level::loadLevel(){
    SDL_Texture* newTexture = NULL;

        //Load image at specified path
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
        // cout<<newTexture<<endl;
    return newTexture;
}



ParkingSpot* Level::getParking(){
    return parking;
};