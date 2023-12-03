#include "coins.hpp"

Coins::Coins (SDL_Renderer* Rndr, string path, SDL_Rect sRect, SDL_Rect mRect) : Objects(Rndr, sRect, mRect) {
    // cout<<path<<endl;
    image = loadImage(path);
    // cout<<"Try Coin"<<endl;
    // cout<<image;
}

void Coins::drawCoin() {
    SDL_RenderCopy(renderer, image, &srcRect, &moverRect);
    // cout<<"drew coin"<<endl;
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

    // moverRect.x += static_cast<int>(velocity * sin(angle*(M_PI/180)));
    // moverRect.y -= static_cast<int>(velocity * cos(angle*(M_PI/180)));
    // SDL_RenderCopyEx(renderer, image, &srcRect, &moverRect, angle, &center, SDL_FLIP_NONE);
    // cout<<angle<<endl;
}