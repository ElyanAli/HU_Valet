#include "objects.hpp"


Objects::Objects(SDL_Renderer* rndr){
    renderer = rndr;
}

int Objects::getPositionX(){
    return positionX;
}

int Objects::getPositionY(){
    return positionY;
}

SDL_Rect* Objects::getSrcRect(){
    return srcRect;
}

void Objects::setImage(string img){
    string imgstr = "./images/"+img;
    image = loadImage(imgstr);
};
