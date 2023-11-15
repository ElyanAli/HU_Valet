#include "car.hpp"

Car::Car (SDL_Renderer* Rndr, SDL_Rect rect, SDL_Rect mRect) : Objects(Rndr, rect, mRect) {}

void Car::accelerate() {}
void Car::deaccelerate() {}
void Car::turnLeft() {}
void Car::turnRight() {}
void Car::releaseAccelerate() {}
void Car::releaseBreak() {}
void Car::straighten() {}