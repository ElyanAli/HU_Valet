#include "car.hpp"

Car::Car (SDL_Renderer* Rndr, string path, SDL_Rect sRect, SDL_Rect mRect) : Objects(Rndr, sRect, mRect) {
    cout<<path<<endl;
    image = loadImage(path);
    cout<<image;
    angle = 90.0;
}

void Car::draw() {
    // Objects::draw();
    // SDL_RenderCopy(renderer, image, &srcRect, &moverRect);
    // cout<<moverRect<<endl;
    SDL_RenderCopyEx(renderer, image, &srcRect, &moverRect, angle, NULL, SDL_FLIP_NONE);
}

void Car::accelerate() {
    moverRect.y = moverRect.y + 5;
}
void Car::deaccelerate() {
    moverRect.y = moverRect.y - 3;
}
void Car::turnLeft() {
    angle -= 5;
}
void Car::turnRight() {
    angle += 5;
}
void Car::releaseAccelerate() {
    moverRect.y = moverRect.y - 1;
}
void Car::releaseBreak() {}
void Car::straighten() {
    angle -= 5;
}