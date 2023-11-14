#include "objects.hpp"

Objects::Objects(){
    
}

Objects::Objects(SDL_Renderer* rndr, SDL_Rect rect, SDL_Rect mrect){
    srcRect = rect;
    renderer = rndr;
    moverRect = rect;
}

int Objects::getPositionX(){
    return srcRect.x;
}

int Objects::getPositionY(){
    return srcRect.y;
}

SDL_Rect* Objects::getSrcRect(){
    return &srcRect;
}

void Objects::setImage(string img){
    string imgstr = "./images/"+img;
    image = loadImage(imgstr);
};

SDL_Texture* Objects::loadImage(string path){
    SDL_Surface *imageSurface = SDL_LoadBMP(path.c_str());
    SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    SDL_RenderCopy(renderer, imageTexture, &srcRect, &moverRect);
    SDL_RenderPresent(renderer);
    return imageTexture;
}
