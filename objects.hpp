#include <iostream>
// #include <SDL.h>
#include <SDL2/SDL.h>
#pragma once
#include <SDL2/SDL_image.h>
using namespace std;

class Objects{
    protected:
        SDL_Texture* image;
        SDL_Renderer* renderer;
        SDL_Rect srcRect;
        SDL_Rect moverRect;
        SDL_Texture* loadImage(string);
    public:
        Objects();
        virtual void draw();
        Objects(SDL_Renderer*, SDL_Rect, SDL_Rect );
        SDL_Rect getMoverRect() const;
        void setImage(string img);
        SDL_Point getPosition();
        virtual float getAngle();
        virtual ~Objects();
};