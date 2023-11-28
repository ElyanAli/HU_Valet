#include "levelButton.hpp"
#include <SDL_image.h>



levelButton::levelButton(){}
levelButton::levelButton(SDL_Renderer* renderer, SDL_Rect srct, SDL_Rect mrct, string p): ren(renderer), buttonPath(p){
    string play = p;
    SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( play.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", play.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", play.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
        
	}
    texture = newTexture;
    srect = srct;
    drect = mrct;

    
}



SDL_Texture* levelButton::loadTexture( std::string path )
{
	//The final texture
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
        newTexture = SDL_CreateTextureFromSurface(ren, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}






void levelButton::update(Mouse& mouse){
    
        if (SDL_HasIntersection(&drect, &mouse.point)){
            isToggled = true;
            if (isToggled){
                loadTexture("./images/welcom2");
                cout<<"hellooo"<<endl;
                string newimage = "./images/welcom2";
                // SDL_Surface* newScreen = IMG_Load(newimage.c_str());
                // SDL_RenderCopy(ren, texture, NULL, NULL);
                // if (newScreen != nullptr){

                //     SDL_DestroyTexture(texture);

                //     texture = SDL_CreateTextureFromSurface(ren, newScreen);

                //     SDL_FreeSurface(newScreen);

                // } 
            }
            srect.x = 400; 
        }
        else{
            isToggled = false;
            srect.x = 0;
        cout<<"hiiiiiiiiiii"<<endl;
        }
}

void levelButton::draw(){
    SDL_RenderCopy(ren, texture, &srect, &drect);
}