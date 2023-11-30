#include "welcomeScreen.hpp"

welcomeScreen::welcomeScreen(){}

welcomeScreen::welcomeScreen( SDL_Renderer* r)
    : renderer(r){
        start = new levelButton(renderer, {7, 34, 91, 34}, {450, 200, 91, 34}, "./images/play3.png");
        screenPath = "./images/welcome3.png";
        mouse = new Mouse(r, {0, 0, 49, 50}, {1000, 600, 49, 50});
        // (*start).srect.y = 0;
        // (*start).drect.x = 640 - (*start).drect.w / 2;
        // (*start).drect.y = 200;   
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
welcomeScreen::~welcomeScreen() {
        
    }
    