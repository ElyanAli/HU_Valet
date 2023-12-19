#include "welcomeScreen.hpp"

welcomeScreen::welcomeScreen(){}

welcomeScreen::welcomeScreen( SDL_Renderer* r)
    : renderer(r){
        start = new button(renderer, {0, 0, 107, 101}, {472, 111, 107, 101}, "./images/playbutton.png");
        screenPath = "./images/welcomeScreen.png";
        mouse = new Mouse(r, {0, 0, 457, 531}, {1000, 600, 50, 60});  
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

void welcomeScreen::drawMouse(){
    mouse->draw();
}

bool welcomeScreen::update(bool buttonClicked){
    mouse->update();
    if (buttonClicked){
        return start->update(*mouse);
    }
    else return false;
}

    //destructor
welcomeScreen::~welcomeScreen(){
    delete mouse;
    delete start;
    SDL_DestroyTexture(startTexture);
    startTexture = nullptr;
}
    