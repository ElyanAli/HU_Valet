#include "level.hpp"

Level::Level(SDL_Renderer* r, int level, parkingSpot* pSpot, string levelPath, string carPath, SDL_Rect carSrc, SDL_Rect carMover){
    path = levelPath;
    parking = new parkingSpot(*pSpot);
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
void Level::insertObstacle(SDL_Renderer* r, string pth, SDL_Rect rct, SDL_Rect mrct){
    Obstacle* thisObstacle = new Obstacle(r, pth, rct, mrct);
    obstacles.push_back(thisObstacle);
}


void Level::drawLevel(){
    SDL_RenderCopy(renderer, image, NULL, NULL);
    for(int i = 0;  i < obstacles.size(); i++){
        obstacles[i]->drawObstacle();
    }
    playerCar->draw();
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