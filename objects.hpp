#include <iostream>
// #include <SDL.h>
#include <SDL.h>
#pragma once
#include <SDL_image.h>
using namespace std;

class Objects{
    protected:
        SDL_Texture* image;
        SDL_Renderer* renderer;
        SDL_Rect srcRect;
        SDL_Texture* loadImage(string);
    public:
        Objects(SDL_Renderer*, SDL_Rect );
        int getPositionX();
        int getPositionY();
        SDL_Rect* getSrcRect();
        void setImage(string img);
};