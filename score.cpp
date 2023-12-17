#include "score.hpp"


void Score::loadHighScore(){
    ifstream highScoreFile;
    highScoreFile.open("highScore.txt");
    if (highScoreFile.good()){
        highScoreFile>>highScore;
    }

}


Score::Score(SDL_Renderer* rndr): digit(rndr){
    
    renderer = rndr;
    xPos = 950;
    yPos = 60;
    xHome = 300;
    yHome = 255;
    currentGameScore =0;
    currentLevelScore = 0;
    highScore = 0;
    loadHighScore();
    highScoreText = loadImage("./images/HighScore.png");
    currScoreText = loadImage("./images/currentScore.png");
    levelScoreText = loadImage("./images/levelScore.png");

}

void Score::updateScoreForCoin(){
    currentLevelScore += COINSCORE;
    currentGameScore += COINSCORE;
    checkForHighScore();
}


int Score::getCurrentLevelScore(){
    return currentLevelScore;
}

void Score::checkForHighScore(){
    if (currentGameScore>highScore){
        highScore = currentGameScore;
    }
}

void Score::updateScoreForLevel(int timeRemaining){
    currentLevelScore = 0;
    currentGameScore+= MAXLEVELSCORE* (timeRemaining/60);
    checkForHighScore();
};

void Score::displayScore(){
    int displayScore = currentLevelScore;
    int i = 0;
    
    while (!(displayScore<10))
    {
       digit.drawDigit(displayScore%10, xPos -(20*i), yPos);
       displayScore/=10;
       i+=1;
    }
    digit.drawDigit(displayScore%10, xPos -(20*i), yPos);
    SDL_Rect pos = {xPos -(20*i) - 100 ,yPos, 100, 20};
    SDL_RenderCopy(renderer, levelScoreText, NULL, &pos);
    i = 0;
    displayScore = currentGameScore;
    while (!(displayScore<10))
    {
       digit.drawDigit(displayScore%10, xPos -(20*i), yPos-30);
       displayScore/=10;
       i+=1;
    }
    digit.drawDigit(displayScore%10, xPos -(20*i), yPos-30);
    pos = {xPos -(20*i) - 100, yPos - 30, 100, 20};
    SDL_RenderCopy(renderer, levelScoreText, NULL, &pos);
    i = 0;
    displayScore = highScore;
    while (!(displayScore<10))
    {
       digit.drawDigit(displayScore%10, xPos -(20*i), yPos-60);
       displayScore/=10;
       i+=1;
    }
    digit.drawDigit(displayScore%10, xPos -(20*i), yPos-60);
    pos = {xPos -(20*i) - 100 ,yPos-60, 100, 20};
    SDL_RenderCopy(renderer, highScoreText, NULL, &pos);
    
}

void Score::displayScoreForHome(int angle){
    int i = 0;
    int displayScore = currentGameScore;
    while (!(displayScore<10))
    {
       digit.drawDigit(displayScore%10, xHome -(20*i) + 30, yHome+(12*i), angle);
       displayScore/=10;
       i+=1;
    }
    digit.drawDigit(displayScore%10, xHome -(20*i) + 30, yHome+(12*i), angle);
    i = 0;
    displayScore = highScore;
    while (!(displayScore<10))
    {
       digit.drawDigit(displayScore%10, xHome -(20*i) + 15, yHome-40+(12*i), angle);
       displayScore/=10;
       i+=1;
    }
    digit.drawDigit(displayScore%10, xHome -(20*i) + 15, yHome- 40+(12*i), angle);
    
}

void Score::resetTotalScore(){
    currentGameScore = 0;
    currentLevelScore = 0;
}

bool Score::checkCoinsForCollision(int noOfCoins){
    if (currentGameScore >= noOfCoins){
        return true;
    };
    return false;
}

void Score::updateScoreForRevival(int noOfCoins){
    currentGameScore -= noOfCoins;
    currentLevelScore -= noOfCoins;
};

SDL_Texture* Score::loadImage(string path) {
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
    // cout<<newTexture<<endl;
	return newTexture;
}

void Score::writeToFile(){
    ofstream HighScoreFile("highScore.txt");
    cout<<"file created"<<endl;
    HighScoreFile<<highScore;
    HighScoreFile.close();
}


