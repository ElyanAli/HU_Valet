#include "levelButton.hpp"
#include <SDL_image.h>



levelButton::levelButton(){}
levelButton::levelButton(SDL_Renderer* renderer, SDL_Rect srct, SDL_Rect mrct, string p): ren(renderer), buttonPath(p){
    SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( buttonPath.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", buttonPath.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", buttonPath.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
        
	}
    texture = newTexture;
    srect = srct;
    drect = mrct;
}


void levelButton::update(Mouse& mouse){
    
        if (SDL_HasIntersection(&drect, &mouse.point)){
            isToggled = true;
            cout<<"toggled"<<endl;
            // srect.x = 400; 
        }
        else{
            isToggled = false;
            // srect.x = 0;
        cout<<"hiiiiiiiiiii"<<endl;
        }
}

void levelButton::draw(){
    SDL_RenderCopy(ren, texture, &srect, &drect);
}