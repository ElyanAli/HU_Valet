#include "level.hpp"

void Level::loadObstacles(){
    for(int i = 0; i < obstacles.size(); i++){
        obstacles[i].loadObstacle();
    }
}

void Level::loadCoins(){
    for(int i = 0; i < coins.size(); i++){
        coins[i].loadCoin();
    }
}