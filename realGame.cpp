#include "realGame.hpp"

realGame::realGame(SDL_Renderer* r): gRenderer(r), digitDisplay(r){
    wscreen = new welcomeScreen(gRenderer);
    done = new button(gRenderer, {3,4, 306, 75}, {700, 75, 200, 49}, "./images/done.png");
    revive = new button(gRenderer, {0,0, 287, 56}, {290, 285, 200, 39}, "./images/revive.png");
    backToHome = new button(gRenderer, {3,4, 306, 75}, {510, 285, 200, 49}, "./images/back.png");
    myMouse = new Mouse(r, {0, 0, 457, 531}, {1000, 600, 50, 60});
    scorer = new Score(r);
    gameOverText = loadImage("./images/gameOver.png");
    reviveText = loadImage("./images/reviveText.png");

}

void realGame::createLevel1(){
    ParkingSpot* levelParking = new ParkingSpot(gRenderer, {0, 0, 81, 139}, {754, 445, 70, 90 }, "./images/parking.png");
    Level* level1= new Level(gRenderer, 1, levelParking, "./images/level1.png", "./images/car1_blue.png",{0, 0, 42, 74}, {841, 252, 34, 59});
    // set border obstacles
    level1->insertObstacle("./images/obstacle1.png", {0, 15, 1000, 107}, {0, 0, 1000, 69});
    level1->insertObstacle("./images/obstacle1.png", {0, 180, 75, 278}, {0, 69, 75, 180});
    level1->insertObstacle("./images/obstacle1.png", {894, 166, 106, 285}, {894, 69, 106, 180});
    level1->insertObstacle("./images/obstacle1.png", {145, 383, 415, 75}, {68, 204, 410, 45});
    level1->insertObstacle("./images/obstacle1.png", {655, 373, 195, 78}, {703, 204, 195, 45});
    level1->insertObstacle("./images/obstacle1.png", {0, 645, 80, 256}, {0, 362, 80, 176});
    level1->insertObstacle("./images/obstacle1.png", {93, 646, 415, 48}, {75, 362, 415, 30});
    level1->insertObstacle("./images/obstacle1.png", {901, 629, 99, 258}, {901, 362, 99, 176});
    level1->insertObstacle("./images/obstacle1.png", {671, 629, 207, 49}, {695, 362, 207, 30});
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
    level1->insertCoin({390, 460, 36, 36});
    level1->insertCoin({675, 460, 36, 36});
    levelBoundaries = {20, 980, 0, 600};
    levelComplete = false;
    levels.push_back(level1);
    coinsReqForRevival = 0;
    incReqCoinsBy = 20;
}

void realGame::createLevel2(){
    ParkingSpot* levelParking = new ParkingSpot(gRenderer, {0, 0, 81, 139}, {288, 38, 29, 50}, "./images/parking.png");
    Level* level2 = new Level(gRenderer, 2, levelParking, "./images/level2.png", "./images/car_green.png", {0, 5, 102, 198}, {536, 143, 25, 45});
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
    level2->insertObstacle("./images/car_blue.png", {0, 5, 109, 211}, {322, 38, 25, 45});
    level2->insertObstacle("./images/car_red_rt.png", {0, 0, 96, 184}, {356, 39, 25, 45});
    level2->insertObstacle("./images/car_blue_rt.png", {0, 5, 103, 205}, {492, 42, 25, 45});
    level2->insertObstacle("./images/car_red.png", {0, 0, 101, 189}, {592, 41, 25, 45});
    level2->insertObstacle("./images/car_green_rt.png", {0, 5, 102, 192}, {626, 41, 25, 45});
    level2->insertObstacle("./images/car_blue.png", {0, 5, 109, 211}, {693, 41, 25, 45});
    // insert parked cars as obstacles at bottom;
    level2->insertObstacle("./images/car_green.png", {0, 5, 102, 198}, {165, 446, 25, 45});
    level2->insertObstacle("./images/car_blue.png", {0, 5, 109, 211}, {231, 446, 25, 45});
    level2->insertObstacle("./images/car_red_rt.png", {0, 0, 96, 184}, {265, 446, 25, 45});
    level2->insertObstacle("./images/car_blue_rt.png", {0, 5, 103, 205}, {466, 446, 25, 45});
    level2->insertObstacle("./images/car_red.png", {0, 0, 101, 189}, {535, 446, 25, 45});
    level2->insertObstacle("./images/car_blue.png",{0, 5, 109, 211}, {569, 446, 25, 45});
    level2->insertObstacle("./images/car_blue_rt.png", {0, 5, 103, 205}, {667, 446, 25, 45});
    // insert moving cars on the road
    level2->insertObstacle("./images/ambulance90.png", {0, 3, 129, 57}, {285, 143, 74, 33});
    level2->insertObstacle("./images/ambulance.png", {2, 0, 57, 128}, {459, 289, 33, 74});
    level2->insertObstacle("./images/police90.png", {0, 1, 122, 55}, {597, 331, 69, 32});
    level2->insertObstacle("./images/truck90.png", {0, 2, 127, 60}, {566, 97, 65, 32});
    level2->insertObstacle("./images/truck.png", {2, 0, 60, 127}, {746, 426, 32, 65});

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
    if (coinsReqForRevival<60){
        coinsReqForRevival=60;
    }
    incReqCoinsBy = 50;


}

void realGame::updateCurrentState(SDL_Event& event){
    myMouse->update();

    // check if play is pressed on welcome screen
    if (level ==-1 ){
        if (event.type == SDL_MOUSEBUTTONUP){
            if (wscreen->update(true)){
                level+=1;
                createLevel1();
                scorer->resetTotalScore();
            }
        }
    }
    else if(reviveButtonEnabled){
        if (event.type == SDL_MOUSEBUTTONUP){
            if (revive->update(*myMouse)){
                reviveButtonEnabled = false;
                scorer->updateScoreForRevival(coinsReqForRevival);
                coinsReqForRevival += incReqCoinsBy;
                keyHandler.clearAll();
                cM.revive(levels[level]->playerCar);
            }
            else if (backToHome->update(*myMouse)){
                reviveButtonEnabled = false;
                gameOver = true;
                
            }
        }
    }
    else if (gameOver){
        levels = {};
        gameOver = false;
        keyHandler.clearAll();
        level = -1;
        // scorer->resetTotalScore();
    }
    else if (!reviveButtonEnabled & !gameOver){
        if (event.type== SDL_KEYDOWN || event.type == SDL_KEYUP){
			keyHandler.handleKeyboardEvent(event);
		}
        Car* thisCar = (levels[level]->playerCar);
        SDL_Rect prevCarRect = thisCar->getMoverRect();
        updateCarPos();
        // check for collision with all obstacles
        for (int i = 0; i < levels[level]->obstacles.size(); i++){
            Obstacle* thisObstacle = (levels[level]->obstacles[i]);
            // cout<<cM.checkCollision(thisCar, thisObstacle)<<endl;
            if(cM.checkCollisionObs(thisCar, thisObstacle)){
                bool coinsAvailable = scorer->checkCoinsForCollision(coinsReqForRevival);
                if (coinsAvailable){
                    reviveButtonEnabled = true;
                }
                else{
                    cout<<"Game is Over"<<endl;
                    gameOver = true;
                }
                cM.resolveCollision(thisCar);
                break;
            };
        }

        // check for collection of each coin
        for(int i = 0; i < levels[level]->coins.size(); i++){
            // cout<<levels[level]->coins.size()<< ", "<< i<<"\n";
            Coin* thisCoin =  (levels[level]->coins[i]);
            if(cM.checkCollisionCoin(thisCar, thisCoin)){
                std::cout<<"coin collected"<<"\n";
                cM.resolveCoinCollision(thisCoin);
                scorer->updateScoreForCoin();
            }
        }
        // check if car is parked in the spot
        if(cM.checkParking(thisCar, levels[level]->getParking())){
            levelComplete = true;
            cout<<"parked"<<"\n";
        }else{
            levelComplete = false;
        }

        if (levelComplete){
            // check if the next button is pressed
            if (event.type == SDL_MOUSEBUTTONUP){
                if (done->update(*myMouse)){
                    scorer->updateScoreForLevel(60);
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
    if (keyHandler.isPressed(SDLK_s) && keyHandler.isPressed(SDLK_LGUI)){
        levels[level]->playerCar->saveRect();  
    }

}

void realGame::drawCurrent(){
    if (level == -1){
        wscreen->displayScreen();
        wscreen->displayButton();
        wscreen->update(false);
        wscreen->drawMouse();
        scorer->displayScoreForHome();
    }
    else{
        levels[level]->drawLevel();
        if (levelComplete){
            done->draw();
        }
        scorer->displayScore();
        if (reviveButtonEnabled){
            SDL_Rect pos = {153, 325, 400, 23};
            revive->draw();
            backToHome->draw();
            SDL_RenderCopy(gRenderer, reviveText, NULL, &pos);
            displayNumber(coinsReqForRevival, 22, 575, 325);
        }
        else if(gameOver){
            SDL_Rect pos = {337, 198, 327, 188};
            SDL_RenderCopy(gRenderer, gameOverText, NULL, &pos);
        }
        myMouse->draw();
        
    }
};

SDL_Texture* realGame::loadImage(string path){
    SDL_Texture* newTexture = NULL;
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
        // cout<<newTexture<<endl;
    return newTexture;
}

void realGame::displayNumber(int num, int x, int y){
    int i = to_string(num).length() - 1;
    while (!(num < 10)){
        digitDisplay.drawDigit(num%10, x + (27 * i),y );
        i--;
        num/=10;
    }
    digitDisplay.drawDigit(num, x + (27 * i),y );

}

void realGame::displayNumber(int num, int w, int x, int y){
    int i = to_string(num).length() - 1;
    while (!(num < 10)){
        digitDisplay.drawDigit(num%10, x + (27 * i),y , w, w);
        i--;
        num/=10;
    }
    digitDisplay.drawDigit(num, x + (27 * i),y, w, w );

}

void realGame::delay(){
    if(gameOver){
        SDL_Delay(1000);
        SDL_Event* e = nullptr;
        updateCurrentState(*e);
        cout<<"game Ended";
    }
    if (level>=0){
        SDL_Delay(30);
    }
}

