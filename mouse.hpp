#pragma once
#include <sdl.h>
#include <sdl_image.h>
#include <sdl_mixer.h>
#include "objects.hpp"



class Mouse: public Objects{
public:
    SDL_Texture * tex;
    SDL_Rect rect;
    SDL_Rect point;
    SDL_Renderer* ren;
    
    Mouse(SDL_Renderer*, SDL_Rect, SDL_Rect);
    // Mouse(SDL_Renderer* renderer,SDL_Texture * texterer);
    
    void update();
    
    void draw();
};
