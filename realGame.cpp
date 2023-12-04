#include "realGame.hpp"

realGame::realGame(SDL_Renderer* r): gRenderer(r){
    wscreen = new welcomeScreen(gRenderer);
    done = new levelButton(gRenderer, {0,0, 52, 54}, {800, 50, 52, 54}, "./images/done.png");
    myMouse = new Mouse(r, {0, 0, 457, 531}, {1000, 600, 50, 60});
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
    levelBoundaries = {20, 980, 0, 600};




    levelComplete = false;
    levels.push_back(level1);
}

void realGame::createLevel2(){
    ParkingSpot* levelParking = new ParkingSpot(gRenderer, {0, 0, 81, 139}, {288, 38, 29, 50}, "./images/parking.png");
    Level* level2 = new Level(gRenderer, 2, levelParking, "./images/level2.png", "./images/car_green.png", {0, 0, 113, 198}, {536, 143, 25, 45});
    levels.push_back(level2);
    levelBoundaries = {132, 868, 0, 535};
    // insert obstacles
    level2->insertObstacle("./images/obstacle2.png", {0, 0, 473, 276}, {500, 188, 262, 175});
    level2->insertObstacle("./images/obstacle3.png", {0, 0, 519, 283}, {180, 188, 250, 187});
    level2->insertObstacle("./images/obstacle4.png", {0, 104, 1038, 26}, {143, 496, 577, 19});
    level2->insertObstacle("./images/obstacle4.png", {0, 0, 31, 105}, {143, 440, 20, 57});
    level2->insertObstacle("./images/obstacle4.png", {1010, 0, 31, 105}, {700, 440, 20, 57});
    level2->insertObstacle("./images/obstacle5.png", {0, 0, 1053, 33}, {362, 0, 498, 24});
    level2->insertObstacle("./images/obstacle5.png", {1021, 33, 31, 656}, {843, 21, 17, 430});
    level2->insertObstacle("./images/obstacle6.png", {0, 4, 94, 98}, {143, 12, 81, 89});
    level2->insertObstacle("./images/obstacle7.png", {0, 0, 78, 78}, {802, 468, 52, 52});
    // insert parked cars as obstacles at top;
    level2->insertObstacle("./images/car_red.png", {0, 0, 101, 189}, {256, 41, 25, 45});
    level2->insertObstacle("./images/car_blue.png", {0, 0, 114, 211}, {322, 38, 25, 45});
    level2->insertObstacle("./images/car_red_rt.png", {0, 0, 101, 189}, {356, 39, 25, 45});
    level2->insertObstacle("./images/car_blue_rt.png", {0, 0, 114, 211}, {492, 42, 25, 45});
    level2->insertObstacle("./images/car_red.png", {0, 0, 101, 189}, {592, 41, 25, 45});
    level2->insertObstacle("./images/car_green_rt.png", {0, 0, 113, 198}, {626, 41, 25, 45});
    level2->insertObstacle("./images/car_blue.png", {0, 0, 114, 211}, {693, 41, 25, 45});
    // insert parked cars as obstacles at bottom;
    level2->insertObstacle("./images/car_green.png", {0, 0, 113, 198}, {165, 446, 25, 45});
    level2->insertObstacle("./images/car_blue.png", {0, 0, 114, 211}, {231, 446, 25, 45});
    level2->insertObstacle("./images/car_red_rt.png", {0, 0, 101, 189}, {265, 446, 25, 45});
    level2->insertObstacle("./images/car_blue_rt.png", {0, 0, 114, 211}, {466, 446, 25, 45});
    level2->insertObstacle("./images/car_red.png", {0, 0, 101, 189}, {535, 446, 25, 45});
    level2->insertObstacle("./images/car_blue.png",{0, 0, 114, 211}, {569, 446, 25, 45});
    level2->insertObstacle("./images/car_blue_rt.png", {0, 0, 114, 211}, {667, 446, 25, 45});
    // insert moving cars on the road
    level2->insertObstacle("./images/ambulance90.png", {0, 1, 129, 59}, {285, 143, 74, 33});
    level2->insertObstacle("./images/ambulance.png", {0, 0, 59, 128}, {459, 289, 33, 74});
    level2->insertObstacle("./images/police90.png", {0, 0, 126, 56}, {597, 331, 69, 32});
    level2->insertObstacle("./images/truck90.png", {0, 0, 127, 62}, {566, 97, 65, 32});
    level2->insertObstacle("./images/truck.png", {0, 0, 62, 127}, {746, 426, 32, 65});

    // insert coins
    level2->insertCoin({496, 451, 36, 36});
    level2->insertCoin({611, 451, 36, 36});
    level2->insertCoin({311, 451, 36, 36});
    level2->insertCoin({778, 271, 36, 36});
    level2->insertCoin({733, 48, 36, 36});
    level2->insertCoin({537, 48, 36, 36});
    level2->insertCoin({432, 48, 36, 36});
    level2->insertCoin({166, 124, 36, 36});
    level2->insertCoin({459, 226, 36, 36});


}

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
                // std::cout<<"collided with"<<thisObstacle->getPath()<<"\n";
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
                    if (level == 1){
                        createLevel2();
                    }else{
                        level = -1;
                        levels = {};
                    }
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

