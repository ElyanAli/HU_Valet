#include "coin.hpp"

Coin::Coin (SDL_Renderer* Rndr, SDL_Rect mRect) : Objects(Rndr, {74, 0, 36, 36}, mRect) {
    cout<<"loading coin"<<"\n";
    image = loadImage(path);
    cout<<"loaded coin"<<"\n";
    // cout<<"Try Coin"<<endl;
    // cout<<image;
}

void Coin::updateMoverRect(int width){
    moverRect.x += ((moverRect.w - width)/2);
    moverRect.w = width;
}

void Coin::drawCoin() {
    if (!collected){
        SDL_RenderCopy(renderer, image, &srcRect, &moverRect);
        // cout<<"drew coin"<<endl;
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
    // moverRect.x += static_cast<int>(velocity * sin(angle*(M_PI/180)));
    // moverRect.y -= static_cast<int>(velocity * cos(angle*(M_PI/180)));
    // SDL_RenderCopyEx(renderer, image, &srcRect, &moverRect, angle, &center, SDL_FLIP_NONE);
    // cout<<angle<<endl;
}