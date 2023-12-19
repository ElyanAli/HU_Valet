#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <SDL2/SDL_m.h>
#include "objects.hpp"



class Mouse{
    private:
        SDL_Texture * tex;
        SDL_Rect rect;
        SDL_Renderer* ren;
    public:
        SDL_Rect point;
        
        Mouse(SDL_Renderer*, SDL_Rect, SDL_Rect);
        void update();
        void draw();
        ~Mouse();
};