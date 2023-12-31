#include "digits.hpp"

Digits::Digits(SDL_Renderer* Rndr) : Objects(Rndr, {392, 0, 30, 35}, {}) {
    image = loadImage(path);
}

SDL_Rect Digits::getMover(int posX, int posY){
    return {posX, posY, 20, 20};
}

SDL_Rect Digits::getMover(int posX, int posY, int w, int h){
    return {posX, posY, w, h};
}


void Digits::drawDigit(int digit, int posX, int posY) {
    SDL_Rect mover= getMover(posX, posY);
    SDL_RenderCopy(renderer, image, &digitSRect[digit], &mover);
}

void Digits::drawDigit(int digit, int posX, int posY, int angle) {
    SDL_Rect mover= getMover(posX, posY);
    SDL_RenderCopyEx(renderer, image, &digitSRect[digit], &mover, angle, NULL, SDL_FLIP_NONE);
}

void Digits::drawDigit(int digit, int posX, int posY, int w, int h) {
    SDL_Rect mover= getMover(posX, posY, w, h);
    SDL_RenderCopy(renderer, image, &digitSRect[digit], &mover);
}