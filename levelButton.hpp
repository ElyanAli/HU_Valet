#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "mouse.hpp"


class levelButton{
    
    SDL_Renderer* ren;
    SDL_Texture* texture;
    SDL_Rect srect, drect;
    bool isToggled = false;
    std::string buttonPath;
    public:
        levelButton();
        levelButton (SDL_Renderer*, SDL_Rect, SDL_Rect, std::string);;
        void update(Mouse&);
        void draw();

    // virtual ~levelButton();
};