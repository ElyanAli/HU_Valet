#pragma once
#include <iostream>
#include "digits.hpp"
#include "CollisionManager.hpp"
#include "SDL2/SDL.h"
#include <fstream>
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
        SDL_Texture* highScoreText;
        SDL_Texture* currScoreText;
        SDL_Texture* levelScoreText;
        void loadHighScore();

    public:
        Score(SDL_Renderer*);
        void updateScoreForLevel(int);
        void updateScoreForCoin();
        void displayScore();
        void displayScoreForHome(int);
        int getCurrentLevelScore();
        void resetTotalScore();
        bool checkCoinsForCollision(int);
        void updateScoreForRevival(int);
        void writeToFile();
        SDL_Texture* loadImage(string);
        friend class CollisionManager;
        
        

};