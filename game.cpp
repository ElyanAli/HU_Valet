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


Game::Game() : gWindow(nullptr), gRenderer(nullptr), assets(nullptr), gTexture(nullptr) {}
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
		gWindow = SDL_CreateWindow( "HU Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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

			}
		}
	}
	 ////
	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	assets = loadTexture("./images/car1_blue.png");
    gTexture = loadTexture("./images/level1.png");
	// cout<<gTexture<<endl;
	if(assets==NULL || gTexture==NULL)
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
	welcomeScreen w_screen;
	SDL_Rect playerCarMoverRect = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 42, 74};
	SDL_Rect playerCarSrcRect = {0, 0, 42, 74};
	playerCar = new Car(gRenderer, "images/car1_blue.png", playerCarSrcRect, playerCarMoverRect);
    // Car playerCar(gRenderer, {0, 0, 40, 74}); // Add SDL Rect here!!
    // playerCar = Car(gRenderer, {0, 0, 40, 74});
	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			

            switch (e.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
				pressedKeys.insert(e.key.keysym.sym);
                HandleKeyPress(e.key.keysym.sym);
                break;
            case SDL_KEYUP:
                HandleKeyRelease(e.key.keysym.sym);
				pressedKeys.erase(e.key.keysym.sym);
                break;
            default:
                break;
            }
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		// SDL_RenderCopy(w_screen.renderer, gTexture, NULL, NULL);
		// SDL_CreateRenderer(w_screen.window, -1, 0);
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		playerCar->draw(); ///
		// drawObjects(gRenderer, assets);

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(50);	//causes sdl engine to delay for specified miliseconds
	}
			
}

void Game::HandleKeyPress(SDL_Keycode key) {
	cout << "Key pressed: " << key << endl;
	double v = 5.0; // constant velocity for simplicity
    double phi = 0.0; // steering rate

	if (pressedKeys.count(SDLK_UP))
	{
		playerCar->accelerate();
	}
	if (pressedKeys.count(SDLK_DOWN))
	{
		playerCar->deaccelerate();
	}
	if (pressedKeys.count(SDLK_LEFT))
	{
		playerCar->turnLeft();
		phi = -0.7;
	}
	if (pressedKeys.count(SDLK_RIGHT))
	{
		playerCar->turnRight();
		phi = 0.7;
	}

    // switch (key)
    // {
    // case SDLK_UP:
    //     playerCar->accelerate();
	// 	// playerCar->update(v, phi);
    //     break;
    // case SDLK_DOWN:
    //     playerCar->deaccelerate();
	// 	// playerCar->update(-v, phi);
    //     break;
    // case SDLK_LEFT:
    //     playerCar->turnLeft();
	// 	phi = -0.7; // adjust steering rate as needed
    //     // playerCar->update(v, phi);
    //     break;
    // case SDLK_RIGHT:
	// 	playerCar->turnRight();
	// 	phi = 0.7; // adjust steering rate as needed
    //     // playerCar->update(v, phi);
    //     // playerCar->turn(-1);
    //     break;
    // default:
    //     break;
    // }
	// playerCar->update(1000.0f/60);
}

void Game::HandleKeyRelease(SDL_Keycode key) {
    // switch (key)
    // {
    // case SDLK_UP:
    //     playerCar->releaseAccelerate();
    //     break;
    // case SDLK_DOWN:
    //     playerCar->releaseBreak();
    //     break;
    // case SDLK_RIGHT:
    // case SDLK_LEFT:
    //     playerCar->straighten();
    //     break;
    // default:
    //     break;
    // }
	if (pressedKeys.count(SDLK_UP))
	{
		playerCar->accelerate();
	}
	if (pressedKeys.count(SDLK_DOWN))
	{
		playerCar->deaccelerate();
	}
	if (pressedKeys.count(SDLK_LEFT))
	{
		playerCar->turnLeft();
		// phi = -0.7;
	}
	if (pressedKeys.count(SDLK_RIGHT))
	{
		playerCar->turnRight();
		// phi = 0.7;
	}
}