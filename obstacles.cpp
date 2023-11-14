#include "obstacles.hpp"


Obstacles::Obstacles(SDL_Renderer* r, string pth, SDL_Rect rct): Objects(r, rct) , path(pth){}


void Obstacles::loadObstacles(){
    loadImage(path);
};