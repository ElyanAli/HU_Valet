#include "mouse.hpp"


Mouse::Mouse(SDL_Renderer* renderer, SDL_Rect srct, SDL_Rect mrct):  ren(renderer), rect(srct), point(mrct) {
        string mouse_image = "./images/mouse.png";
        SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( mouse_image.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", mouse_image.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
                newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", mouse_image.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
        
	}
        tex = newTexture;  
        
}

void Mouse::update(){
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        point.x = mouseX;
        point.y = mouseY;
        
    }

void Mouse::draw(){
        SDL_ShowCursor(false);
        SDL_RenderCopy(ren, tex, &rect, &point);
    }


Mouse::~Mouse(){
	SDL_DestroyTexture(tex);
};