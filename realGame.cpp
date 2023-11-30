#include "realGame.hpp"

realGame::realGame(SDL_Renderer* r): gRenderer(r){
    wscreen = new welcomeScreen(gRenderer);
}
void realGame::createLevel1(){
    parkingSpot levelParking = new parkingSpot();
    Level* level1= new Level(gRenderer, 1, )
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

void realGame::drawCurrent(){
    if (level == -1){
        wscreen->displayButton();
        wscreen->displayButton();
        wscreen->update(false);
        wscreen->drawMouse();
    }
    else{
        levels[level]->drawLevel();
    }
};



