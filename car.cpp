#include "car.hpp"
#include <math.h>

Car::Car (SDL_Renderer* Rndr, string path, SDL_Rect sRect, SDL_Rect mRect) : Objects(Rndr, sRect, mRect) {
    cout<<path<<endl;
    image = loadImage(path);
    cout<<image;
    angle = 0.0;
    theta = 0;
    delta = 0;
    center ={21,37};
}

void Car::draw() {
    moverRect.x += static_cast<int>(velocity * sin(angle*(M_PI/180)));
    moverRect.y -= static_cast<int>(velocity * cos(angle*(M_PI/180)));
    SDL_RenderCopyEx(renderer, image, &srcRect, &moverRect, angle, &center, SDL_FLIP_NONE);
    // cout<<angle<<endl;
}


void Car::accelerate() {
    if (velocity <= 15){
        velocity += acceleration;
        
    }
}
void Car::decelerate() {
    if (velocity >= -15){
        velocity -= acceleration;
    }
    
}
void Car::turnLeft() {
    angle -= ANGLE_CHANGE;
}
void Car::turnRight() {
    angle += ANGLE_CHANGE;
}
void Car::releaseAccelerate() {
    while(velocity>0){
        velocity -= 5;
        if (velocity< 0){
            velocity = 0;
            break;
        }
        draw();
    }
}
void Car::releaseDeceleration() {
    while(velocity<0){
        velocity += 5;
        draw();
        if (velocity> 0){
            velocity = 0;
            break;
        }
    }
}
