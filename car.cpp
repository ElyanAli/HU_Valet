#include "car.hpp"
#include <math.h>

Car::Car (SDL_Renderer* Rndr, string path, SDL_Rect sRect, SDL_Rect mRect) : Objects(Rndr, sRect, mRect) {
    cout<<path<<endl;
    image = loadImage(path);
    angle = 270;
    center ={moverRect.w/2,moverRect.h/2};
}

void Car::draw() {
    moveCar();
    SDL_RenderCopyEx(renderer, image, &srcRect, &moverRect, angle, &center, SDL_FLIP_NONE);
    // cout<<angle<<endl;
}

void Car::moveCar(){
    moverRect.x += static_cast<int>(velocity * sin(angle*(M_PI/180)));
    moverRect.y -= static_cast<int>(velocity * cos(angle*(M_PI/180)));
}
void Car::accelerate() {
    if (velocity < 6){
        velocity += acceleration;
    }
    // std::cout<<velocity<<std::endl;
}
void Car::decelerate() {
    if (velocity > -6){
        velocity -= acceleration;
    }
    
}

void Car::setAngle(){
    if (angle< (-359)){
        angle += 360;
    }else if (angle>359){
        angle +=360;
    }
}


void Car::turnLeft() {
    setAngle();
    angle -= ANGLE_CHANGE;
}
void Car::turnRight() {
    setAngle();
    angle += ANGLE_CHANGE;
}
void Car::releaseAccelerate() {
    while(velocity>0){
        velocity -= acceleration;
        if (velocity< 0){
            velocity = 0;
            break;
        }
    }
}

void Car::releaseDeceleration() {
    while(velocity<0){
        velocity += acceleration;
        draw();
        if (velocity> 0){
            velocity = 0;
            break;
        }
    }
}

int Car::getAngle() const{
    return angle;
}

void Car::hardSetCarPos(float overlap){
    velocity -= velocity;
}

