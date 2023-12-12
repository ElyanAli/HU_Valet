#pragma once
#include <iostream>
#include "digits.hpp"
#include "CollisionManager.hpp"
#include "SDL2/SDL.h"
using namespace std;




class Score{
    private:
        SDL_Renderer* renderer;
        const int COINSCORE = 20;
        const int MAXLEVELSCORE = 500;
        int currentLevelScore;
        int currentGameScore;
        int highScore;
        int xPos, yPos, xHome, yHome;
        void checkForHighScore();
        Digits digit;

    public:
        Score(SDL_Renderer*);
        void updateScoreForLevel(int);
        void updateScoreForCoin();
        void displayScore();
        void displayScoreForHome();
        int getCurrentLevelScore();
        void resetTotalScore();
        bool checkCoinsForCollision(int);
        void updateScoreForRevival(int);
        friend class CollisionManager;
        

};