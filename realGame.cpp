#include "realGame.hpp"

realGame::realGame(SDL_Renderer* r): gRenderer(r){
    wscreen = new welcomeScreen(gRenderer);
}
void realGame::createLevel1(){
    parkingSpot* levelParking = new parkingSpot(451, 532, 697, 823);
    Level* level1= new Level(gRenderer, 1, levelParking, "./images/level1.png", "./images/car1_blue.png",{0, 0, 42, 74}, {741, 482, 42, 74});
    levels.push_back(level1);
}



void realGame::updateCurrentState(SDL_Event& event){
    if (level ==-1 ){

        if (event.type == SDL_MOUSEBUTTONUP){
            if (wscreen->update(true)){
                level+=1;
                createLevel1();
            }
        }
    }
    else{
        if (event.type== SDL_KEYDOWN || event.type == SDL_KEYUP){
			keyHandler.handleKeyboardEvent(event);
		}
    }
}
void realGame::updateCarPos(){
	if (keyHandler.isPressed(SDLK_UP)){
		levels[level]->playerCar->accelerate();
	}
	if (keyHandler.isPressed(SDLK_DOWN))
	{
		levels[level]->playerCar->decelerate();
	}
	if (keyHandler.isPressed(SDLK_LEFT))
	{
		levels[level]->playerCar->turnLeft();
	}
	if (keyHandler.isPressed(SDLK_RIGHT))
	{
		levels[level]->playerCar->turnRight();
	}
	if (keyHandler.isReleasedNow(SDLK_UP) ){
        levels[level]->playerCar->releaseAccelerate();
	}
    if (keyHandler.isReleasedNow(SDLK_DOWN)){
        levels[level]->playerCar->releaseDeceleration();
	}

}

void realGame::drawCurrent(){
    if (level == -1){
        wscreen->displayScreen();
        wscreen->displayButton();
        wscreen->update(false);
        wscreen->drawMouse();
    }
    else{
        updateCarPos();
        levels[level]->drawLevel();
    }
};

void realGame::delay(){
    if (level>=0){
        SDL_Delay(50);
    }
}

