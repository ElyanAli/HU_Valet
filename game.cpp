#include "game.hpp"
#include "car.hpp"
// #include "changeColourButton.hpp"
// #include "coins.hpp"
// #include "collisionManager.hpp"
// #include "level.hpp"
// #include "levelButton.hpp"
// #include "objects.hpp"
// #include "obstacles.hpp"
// #include "parkingSpot.hpp"
// #include "score.hpp"
// #include "time.hpp"
// #include "ui.hpp"
#include "welcomeScreen.hpp"
// #include "SDL 2/SDL 2"
#include "levelButton.hpp"




Game::Game() : gWindow(nullptr), gRenderer(nullptr), assets(nullptr), gTexture(nullptr), playerCar(gRenderer, {0, 0, 40, 74}, {0, 0, 40, 74})/* level_button(gRenderer, {96, 4, 203, 89}, {500, 500, 203, 89})*/ {
	// level_button = levelButton(gRenderer, {500, 300, 96, 4}, {1000, 600, 96, 4});
}
bool Game::init()
{
	//Initialization flag
	bool success = true;
	
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "HU Valet", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				Game::w = new welcomeScreen(gRenderer);

			}
		}
	}
	// mouse = new Mouse(gRenderer, {0, 0, 49, 50}, {1000, 600, 49, 50});
	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	


	assets = loadTexture("./images/car1_blue.png");
	// startTexture = loadTexture("./images/play3.png");
	if(assets==NULL /*|| gTexture==NULL*/)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
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
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	bool quit = false;
	SDL_Event e;
	
	w->displayScreen();
	w->displayButton();
	
    // level_button.srect.y = 0;
    // level_button.drect.x = 640 - level_button.drect.w / 2;
    // level_button.drect.y = 200;
    
	while( !quit )
	{	
		
		// mouse->update();
		while( SDL_PollEvent( &e ) != 0 )
		{
			w->update(false);

            switch (e.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                HandleKeyPress(e.key.keysym.sym);
                break;
			case SDL_MOUSEBUTTONUP:
				
				w->update(true);

				break;

					
            case SDL_KEYUP:
                HandleKeyRelease(e.key.keysym.sym);
                break;
            default:
                break;
            }

			
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		// SDL_RenderCopy(w_screen.renderer, gTexture, NULL, NULL);
		// SDL_CreateRenderer(w_screen.window, -1, 0);
		// SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		w->displayScreen();
		w->displayButton();
		w->drawMouse();
		// mouse->draw();
		// SDL_RenderCopy(gRenderer, mouseTexture, &mouse.rect, &mouse.point);
		// drawObjects(gRenderer, assets);

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(0);	//causes sdl engine to delay for specified miliseconds
		// SDL_Delay(200);
		
	}
			
}

void Game::HandleKeyPress(SDL_Keycode key) {
    switch (key)
    {
    case SDLK_UP:
        playerCar.accelerate();
        break;
    case SDLK_DOWN:
        playerCar.deaccelerate();
        break;
    case SDLK_LEFT:
        playerCar.turnLeft();
        break;
    case SDLK_RIGHT:
        playerCar.turnRight();
        break;
    default:
        break;
    }
}

void Game::HandleKeyRelease(SDL_Keycode key) {
    switch (key)
    {
    case SDLK_UP:
        playerCar.releaseAccelerate();
        break;
    case SDLK_DOWN:
        playerCar.releaseBreak();
        break;
    case SDLK_RIGHT:
    case SDLK_LEFT:
        playerCar.straighten();
        break;
    default:
        break;
    }
}