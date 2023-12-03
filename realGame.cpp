#include "realGame.hpp"

realGame::realGame(SDL_Renderer* r): gRenderer(r){
    wscreen = new welcomeScreen(gRenderer);
    done = new levelButton(gRenderer, {0,0, 52, 54}, {800, 50, 52, 54}, "./images/done.png");
    myMouse = new Mouse(gRenderer, {0, 0, 49, 50}, {1000, 600, 49, 50});
}
void realGame::createLevel1(){
    ParkingSpot* levelParking = new ParkingSpot(gRenderer, {0, 0, 81, 139}, {754, 445, 70, 90 }, "./images/parking.png");
    Level* level1= new Level(gRenderer, 1, levelParking, "./images/level1.png", "./images/car1_blue.png",{0, 0, 42, 74}, {841, 252, 34, 59});
    // set border obstacles
    level1->insertObstacle("./images/obstacle1.png", {0, 15, 1000, 107}, {0, 0, 1000, 69});
    level1->insertObstacle("./images/obstacle1.png", {0, 180, 90, 278}, {0, 69, 90, 180});
    level1->insertObstacle("./images/obstacle1.png", {894, 166, 106, 285}, {894, 69, 106, 180});
    level1->insertObstacle("./images/obstacle1.png", {145, 383, 415, 75}, {82, 204, 410, 45});
    level1->insertObstacle("./images/obstacle1.png", {655, 373, 195, 78}, {703, 204, 195, 45});
    level1->insertObstacle("./images/obstacle1.png", {0, 645, 80, 256}, {0, 362, 80, 176});
    level1->insertObstacle("./images/obstacle1.png", {93, 646, 415, 48}, {75, 362, 415, 30});
    level1->insertObstacle("./images/obstacle1.png", {891, 629, 109, 258}, {891, 362, 109, 176});
    level1->insertObstacle("./images/obstacle1.png", {671, 629, 207, 49}, {692, 362, 207, 30});
    level1->insertObstacle("./images/obstacle1.png", {0, 945, 1000, 98}, {0, 537, 1000, 63});
    // // set car obstacles in slots on top
    level1->insertObstacle("./images/car1_purple.png", {0, 0, 42, 74}, {390, 72, 34, 50});
    level1->insertObstacle("./images/car1_orange.png", {0, 0, 42, 74}, {245, 72, 34, 50});
    level1->insertObstacle("./images/car1_purple.png", {0, 0, 42, 74}, {170, 72, 34, 50});
    level1->insertObstacle("./images/car1_yellow.png", {0, 0, 42, 74}, {545, 72, 34, 50});
    level1->insertObstacle("./images/car1_yellow.png", {0, 0, 42, 74}, {620, 72, 34, 50});
    level1->insertObstacle("./images/car1_yellow.png", {0, 0, 42, 74}, {695, 72, 34, 50});
    level1->insertObstacle("./images/car1_red.png", {0, 0, 42, 74}, {840, 72, 34, 50});
    // // set car obstacles in slots at bottom
    level1->insertObstacle("./images/car1_purple_rt.png", {0, 0, 42, 74}, {315, 470, 34, 50});
    level1->insertObstacle("./images/car1_orange_rt.png", {0, 0, 42, 74}, {95, 470, 34, 50});
    level1->insertObstacle("./images/car1_purple_rt.png", {0, 0, 42, 74}, {170, 470, 34, 50});
    level1->insertObstacle("./images/car1_yellow_rt.png", {0, 0, 42, 74}, {470, 470, 34, 50});
    level1->insertObstacle("./images/car1_yellow_rt.png", {0, 0, 42, 74}, {620, 470, 34, 50});
    level1->insertObstacle("./images/car1_yellow_rt.png", {0, 0, 42, 74}, {545, 470, 34, 50});
    level1->insertObstacle("./images/car1_red_rt.png", {0, 0, 42, 74}, {840, 470, 34, 50});

    // load coins
    level1->insertCoin({95, 77, 36, 36});
    level1->insertCoin({320, 77, 36, 36});
    level1->insertCoin({470, 77, 36, 36});
    level1->insertCoin({770, 77, 36, 36});
    // level1->insertCoin({770, 460, 36, 36});
    level1->insertCoin({240, 460, 36, 36});
    level1->insertCoin({240, 460, 36, 36});
    level1->insertCoin({390, 460, 36, 36});
    level1->insertCoin({675, 460, 36, 36});





    levelComplete = false;
    levels.push_back(level1);
}

void realGame::createLevel2(){}

void realGame::updateCurrentState(SDL_Event& event){
    myMouse->update();
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
            if(cM.checkCollisionObs(thisCar, thisObstacle)){
                std::cout<<"collided with"<<thisObstacle->getPath()<<"\n";
                cM.resolveCollision(thisCar, prevCarRect);
            };
        }
        for(int i = 0; i < levels[level]->coins.size(); i++){
            // cout<<levels[level]->coins.size()<< ", "<< i<<"\n";
            Coin* thisCoin =  (levels[level]->coins[i]);
            if(cM.checkCollisionCoin(thisCar, thisCoin)){
                std::cout<<"coin collected"<<"\n";
                cM.resolveCoinCollision(thisCoin);
            }
        }
        if(cM.checkParking(thisCar, levels[level]->getParking())){
            levelComplete = true;
            cout<<"parked"<<"\n";
        }else{
            levelComplete = false;
        }
        if (levelComplete){
            if (event.type == SDL_MOUSEBUTTONUP){
                if (done->update(*myMouse)){
                    level+=1;
                    createLevel2();
                };
            }
        }

    }
}
void realGame::updateCarPos(){
	if (keyHandler.isPressed(SDLK_UP)){
		levels[level]->playerCar->accelerate();
        collided = false;
	}
	if (keyHandler.isPressed(SDLK_DOWN))
	{
		levels[level]->playerCar->decelerate();
        collided = false;
	}
	if (keyHandler.isPressed(SDLK_LEFT))
	{
		levels[level]->playerCar->turnLeft();
        collided = false;
	}
	if (keyHandler.isPressed(SDLK_RIGHT))
	{
		levels[level]->playerCar->turnRight();
        collided = false;
	}
	if (keyHandler.isReleasedNow(SDLK_UP) ){
        levels[level]->playerCar->releaseAccelerate();
        collided = false;
	}
    if (keyHandler.isReleasedNow(SDLK_DOWN)){
        levels[level]->playerCar->releaseDeceleration();
        collided = false;
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
        if (levelComplete){
            done->draw();
        }
        myMouse->draw();
    }
};

void realGame::delay(){
    if (level>=0){
        SDL_Delay(30);
    }
}

