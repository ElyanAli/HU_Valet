#include "realGame.hpp"

realGame::realGame(SDL_Renderer* r): gRenderer(r){
    wscreen = new welcomeScreen(gRenderer);
}
void realGame::createLevel1(){
    parkingSpot* levelParking = new parkingSpot(302, 381, 448, 534);
    Level* level1= new Level(gRenderer, 1, levelParking, "./images/level1.png", "./images/car1_blue.png",{0, 0, 42, 74}, {841, 242, 42, 74});
    // set border obstacles
    level1->insertObstacle(gRenderer, "./images/obstacle1.png", {0, 15, 1000, 107}, {0, 0, 1000, 69});
    level1->insertObstacle(gRenderer, "./images/obstacle1.png", {0, 180, 90, 278}, {0, 69, 90, 180});
    level1->insertObstacle(gRenderer, "./images/obstacle1.png", {894, 166, 106, 285}, {894, 69, 106, 180});
    level1->insertObstacle(gRenderer, "./images/obstacle1.png", {145, 373, 421, 87}, {82, 193, 421, 56});
    level1->insertObstacle(gRenderer, "./images/obstacle1.png", {655, 373, 205, 83}, {693, 195, 205, 54});
    level1->insertObstacle(gRenderer, "./images/obstacle1.png", {0, 645, 80, 256}, {0, 372, 80, 166});
    level1->insertObstacle(gRenderer, "./images/obstacle1.png", {93, 646, 426, 53}, {75, 372, 426, 34});
    level1->insertObstacle(gRenderer, "./images/obstacle1.png", {891, 629, 109, 258}, {891, 372, 109, 166});
    level1->insertObstacle(gRenderer, "./images/obstacle1.png", {671, 629, 207, 55}, {692, 372, 207, 35});
    level1->insertObstacle(gRenderer, "./images/obstacle1.png", {0, 945, 1000, 98}, {0, 537, 1000, 63});
    // set car obstacles in slots on top
    level1->insertObstacle(gRenderer, "./images/car1_purple.png", {0, 0, 42, 74}, {390, 72, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_orange.png", {0, 0, 42, 74}, {245, 72, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_purple.png", {0, 0, 42, 74}, {170, 72, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_yellow.png", {0, 0, 42, 74}, {545, 72, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_yellow.png", {0, 0, 42, 74}, {620, 72, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_yellow.png", {0, 0, 42, 74}, {695, 72, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_red.png", {0, 0, 42, 74}, {840, 72, 42, 60});
    // set car obstacles in slots at bottom
    level1->insertObstacle(gRenderer, "./images/car1_purple_rt.png", {0, 0, 42, 74}, {315, 470, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_orange_rt.png", {0, 0, 42, 74}, {95, 470, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_purple_rt.png", {0, 0, 42, 74}, {170, 470, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_yellow_rt.png", {0, 0, 42, 74}, {470, 470, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_yellow_rt.png", {0, 0, 42, 74}, {620, 470, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_yellow_rt.png", {0, 0, 42, 74}, {545, 470, 42, 60});
    level1->insertObstacle(gRenderer, "./images/car1_red_rt.png", {0, 0, 42, 74}, {840, 470, 42, 60});
    levelComplete = false;
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
        Car* thisCar = (levels[level]->playerCar);
        SDL_Rect prevCarRect = thisCar->getMoverRect();
        updateCarPos();
        for (int i = 0; i < levels[level]->obstacles.size(); i++){
            Obstacle* thisObstacle = (levels[level]->obstacles[i]);
            // cout<<cM.checkCollision(thisCar, thisObstacle)<<endl;
            if(cM.checkCollision(thisCar, thisObstacle)){
                std::cout<<"collided with"<<thisObstacle->getPath()<<"\n";
                float distance = sqrt(pow(thisObstacle->getMoverRect().x - prevCarRect.x, 2) + pow(thisObstacle->getMoverRect().y - prevCarRect.y, 2));
                float overlap = thisCar->getMoverRect().w / 2 + thisObstacle->getMoverRect().w / 2 - distance;
                levels[level]->playerCar->hardSetCarPos(overlap);
            };
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
        levels[level]->drawLevel();
    }
};

void realGame::delay(){
    if (level>=0){
        SDL_Delay(50);
    }
}

