#include "button.hpp"




button::button(){}
button::button(SDL_Renderer* renderer, SDL_Rect srct, SDL_Rect mrct, string p): ren(renderer), buttonPath(p){
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


bool button::update(Mouse& mouse){
    
        if (SDL_HasIntersection(&drect, &mouse.point)){
            isToggled = true;
        }
        else{
            isToggled = false;
        }
        return isToggled;
}

void button::draw(){
    SDL_RenderCopy(ren, texture, &srect, &drect);
}

button::~button(){
	SDL_DestroyTexture(texture);
	texture = nullptr;
}