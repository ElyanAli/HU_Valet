#include "coin.hpp"

Coin::Coin (SDL_Renderer* Rndr, SDL_Rect mRect) : Objects(Rndr, {74, 0, 36, 36}, mRect) {
    image = loadImage(path);
}

bool Coin::isCollected(){
    return collected;
}
void Coin::updateMoverRect(int width){
    moverRect.x += ((moverRect.w - width)/2);
    moverRect.w = width;
}

void Coin::draw() {
    if (!collected){
        SDL_RenderCopy(renderer, image, &srcRect, &moverRect);
        timerCount += 1;
        if (timerCount> 3){
            if (srcRect.x == 74 && srcRect.w == 36) {
                srcRect.x = 157;
                srcRect.w = 28;
            }
            else if (srcRect.x == 157 && srcRect.w == 28) {
                srcRect.x = 124;
                srcRect.w = 17;
            }
            else if (srcRect.x == 124 && srcRect.w == 17) {
                srcRect.x = 43;
                srcRect.w = 17;
            }
            else if (srcRect.x == 43 && srcRect.w == 17) {
                srcRect.x = 0;
                srcRect.w = 28;
            }
            else if (srcRect.x == 0 && srcRect.w == 28) {
                srcRect.x = 74;
                srcRect.w = 36;
            }
            updateMoverRect(srcRect.w);
            timerCount = 0;
        }
    }
}