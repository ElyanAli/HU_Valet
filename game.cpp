#include "game.hpp"



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

			}
		}
	}
	////make the realGame
	parkingGame = new realGame(gRenderer);
	return success;
}

/*bool Game::loadMedia()
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
*/

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
	// SDL_Rect playerCarMoverRect = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 42, 74};
	// SDL_Rect playerCarSrcRect = {0, 0, 42, 74};
	// playerCar = new Car(gRenderer, "images/car1_blue.png", playerCarSrcRect, playerCarMoverRect);

	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{	
			if (e.type == SDL_QUIT){
				quit = true;
			}else{
				parkingGame->updateCurrentState(e);
			}  
        }

		SDL_RenderClear(gRenderer); //removes everything from renderer
		
		//***********************draw the objects here********************
		parkingGame->drawCurrent();
		// drawObjects(gRenderer, assets);

		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    // SDL_Delay(50);	//causes sdl engine to delay for specified miliseconds
	}
}
			

// void Game::HandleKeyPress() {
// 	if (pressedKeys.count(SDLK_UP))
// 	{
// 		playerCar->accelerate();
// 	}
// 	if (pressedKeys.count(SDLK_DOWN))
// 	{
// 		playerCar->decelerate();
// 	}
// 	if (pressedKeys.count(SDLK_LEFT))
// 	{
// 		playerCar->turnLeft();
// 	}
// 	if (pressedKeys.count(SDLK_RIGHT))
// 	{
// 		playerCar->turnRight();
// 	}
// }

// void Game::HandleKeyRelease() {
//     if (pressedKeys.count(SDLK_UP) ){
//         playerCar->releaseAccelerate();
// 	}
//     if (pressedKeys.count(SDLK_DOWN)){
//         playerCar->releaseDeceleration();
// 	}
// }