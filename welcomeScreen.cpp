#pragma once
#include <iostream>
#include "welcomeScreen.hpp"
#include <SDL.h>

#include "mouse.hpp"
#include "levelButton.hpp"

// #include "changeColourButton.hpp"
using namespace std;


levelButton start;
welcomeScreen::welcomeScreen(){}

welcomeScreen::welcomeScreen( SDL_Renderer* r)
    : renderer(r){
        start = new levelButton(r, {7, 34, 91, 34}, {450, 200, 91, 34}, "./images/play3.png");
        screenPath = "./images/welcome3.png";
    }

SDL_Texture* welcomeScreen::loadImage(string path)
{
    SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
        
	}
    return newTexture;    
    
    }

void welcomeScreen::displayScreen()
{
    SDL_Texture* t = loadImage(screenPath);
    SDL_RenderCopy(renderer, t, NULL, NULL);      
}

void welcomeScreen::displayButton()
{
    start->draw();   
}

    //destructor
welcomeScreen::~welcomeScreen() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    
