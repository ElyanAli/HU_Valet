#include "obstacles.hpp"


Obstacle::Obstacle(SDL_Renderer* r, string pth, SDL_Rect rct, SDL_Rect mrct): Objects(r, rct, mrct) , path(pth){}


void Obstacle::loadObstacle(){
    loadImage(path);
};