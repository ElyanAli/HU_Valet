#pragma once
#include <iostream>
#include <SDL.h>
#include "mouse.hpp"


class levelButton{
    
    SDL_Renderer* ren;
    SDL_Texture* texture;
    SDL_Rect srect, drect;
    bool isToggled = false;
    string buttonPath;
    public:
        levelButton();
        levelButton (SDL_Renderer*, SDL_Rect, SDL_Rect, string);;
        void update(Mouse&);
        void draw();

    // virtual ~levelButton();


    

    
};