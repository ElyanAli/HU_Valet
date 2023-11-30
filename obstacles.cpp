#include "obstacles.hpp"


Obstacle::Obstacle(SDL_Renderer* r, string pth, SDL_Rect rct, SDL_Rect mrct): Objects(r, rct, mrct) , path(pth){
    image = loadImage(path);
}

void Obstacle::drawObstacle(){
    SDL_RenderCopy(renderer, image, &srcRect, &moverRect);
}

