#include "digits.hpp"

Digits::Digits (SDL_Renderer* Rndr, SDL_Rect mRect) : Objects(Rndr, {392, 0, 30, 35}, mRect) {
    cout<<"loading digit"<<"\n";
    image = loadImage(path);
    cout<<"loaded digit"<<"\n";
}

void Digits::drawDigits() {
    SDL_RenderCopy(renderer, image, &srcRect, &moverRect);
}
// 80 % 20 = 4 * 2 = 8 pos of val
// 
void Digits::incDigit(int digitnumber, int tempScoreCount_0th, int tempScoreCount_10th) {
    if (tempScoreCount_0th == 0 && tempScoreCount_10th == 10 && digitnumber == 0) {
        srcRect.x = digitSRect[tempScoreCount_0th + 1].x;
        srcRect.w = digitSRect[tempScoreCount_0th + 1].w;
        srcRect.h = digitSRect[tempScoreCount_0th + 1].h;
    }
    else if (tempScoreCount_0th == 0 && tempScoreCount_10th == 10 && digitnumber == 1) {
        srcRect.x = digitSRect[tempScoreCount_0th].x;
        srcRect.w = digitSRect[tempScoreCount_0th].w;
        srcRect.h = digitSRect[tempScoreCount_0th].h;
    }
    else if (tempScoreCount_0th > 0 && digitnumber == 1) {
        srcRect.x = digitSRect[tempScoreCount_0th].x;
        srcRect.w = digitSRect[tempScoreCount_0th].w;
        srcRect.h = digitSRect[tempScoreCount_0th].h;
    }
    // count++;
}