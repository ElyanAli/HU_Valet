#include "score.hpp"


Score::Score(SDL_Renderer* rndr): digit(rndr){
    renderer = rndr;
    xPos = 950;
    yPos = 60;
    xHome = 500;
    yHome = 300;
    currentGameScore =0;
    currentLevelScore = 0;
    highScore = 0;
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
    i = 0;
    displayScore = currentGameScore;
    while (!(displayScore<10))
    {
       digit.drawDigit(displayScore%10, xPos -(20*i), yPos-14);
       displayScore/=10;
       i+=1;
    }
    digit.drawDigit(displayScore%10, xPos -(20*i), yPos-14);
    i = 0;
    displayScore = highScore;
    while (!(displayScore<10))
    {
       digit.drawDigit(displayScore%10, xPos -(20*i), yPos-28);
       displayScore/=10;
       i+=1;
    }
    digit.drawDigit(displayScore%10, xPos -(20*i), yPos-28);
    
}

void Score::displayScoreForHome(){
    int i = 0;
    int displayScore = currentGameScore;
    while (!(displayScore<10))
    {
       digit.drawDigit(displayScore%10, xHome -(20*i), yHome);
       displayScore/=10;
       i+=1;
    }
    digit.drawDigit(displayScore%10, xHome -(20*i), yHome);
    i = 0;
    displayScore = highScore;
    while (!(displayScore<10))
    {
       digit.drawDigit(displayScore%10, xHome -(20*i), yHome-14);
       displayScore/=10;
       i+=1;
    }
    digit.drawDigit(displayScore%10, xHome -(20*i), yHome- 14);
    
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



