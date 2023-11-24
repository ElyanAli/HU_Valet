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
    // steering = 0;
}

void Car::draw() {
    // Objects::draw();
    // SDL_RenderCopy(renderer, image, &srcRect, &moverRect);
    // cout<<moverRect<<endl;
    
    SDL_RenderCopyEx(renderer, image, &srcRect, &moverRect, angle, &center, SDL_FLIP_NONE);
    cout<<angle<<endl;
}

// void Car::update(double v, double phi) {
//     double width = 42.0;
//     double height = 74.0;

// // Calculate the length of the car
//     double L = sqrt(pow(width, 2) + pow(height, 2));

// // Calculate the distance from the rear axle to the center of gravity
//     double lr = 0.4 * L;


//     // Update the state based on the bicycle model equations
//     double R = L / tan(delta);
//     double beta = atan(lr * tan(delta) / L);

//     // Corrected computation of x_dot and y_dot based on the orientation (theta) of the car
//     double x_dot = v * cos(theta + beta);
//     double y_dot = v * sin(theta + beta);
//     double theta_dot = v * tan(delta) / L;
//     double delta_dot = phi;

//     moverRect.x += static_cast<int>(x_dot * DELTA_T); // Cast to int for rendering
//     moverRect.y += static_cast<int>(y_dot * DELTA_T); // Cast to int for rendering
//     theta += theta_dot * DELTA_T;
//     delta += delta_dot * DELTA_T;

//     // Wrap angle to the range [0, 2*pi)
//     theta = fmod(theta, 2 * M_PI);
//     if (theta < 0)
//         theta += 2 * M_PI;

//     angle = theta * 180 / M_PI;

//     // Debug prints
//     cout << "X: "<< moverRect.x<<", y: "<<moverRect.y<<", Angle: "<<angle<< ", x_dot: " << x_dot << ", y_dot: " << y_dot << ", theta_dot: " << theta_dot << ", delta_dot: " << delta_dot << endl;
// }

// void Car::accelerate(int direction) {
//     acceleration = direction;
// }

// void Car::turn(int s) {
//     steering = s;
// }

// float Car::getAngle() {
//     return angle;
// }

// SDL_Point Car::getAxis() {
//     return axis;
// }

// void Car::update(float delta) {
//     speed += acceleration + delta + max_speed;
//     const float steering_speed = .5f;
//     if (speed > max_speed) speed = max_speed;
//     angle += steering * steering_speed;
//     moverRect.x += cos(angle) + speed + delta;
//     moverRect.y += sin(angle) + speed + delta;

//     acceleration = 0;
//     steering = 0;
// }

void Car::accelerate() {
    
    moverRect.x += static_cast<int>(SPEED * sin(angle*(M_PI/180)));
    moverRect.y -= static_cast<int>(SPEED * cos(angle*(M_PI/180)));
}
void Car::deaccelerate() {
    // moverRect.x -= static_cast<int>(SPEED * cos(angle));
    // moverRect.y -= static_cast<int>(SPEED * sin(angle));
    moverRect.x -= static_cast<int>(SPEED * sin(angle*(M_PI/180)));
    moverRect.y += static_cast<int>(SPEED * cos(angle*(M_PI/180)));
}
void Car::turnLeft() {
    angle -= ANGLE_CHANGE;
}
void Car::turnRight() {
    angle += ANGLE_CHANGE;
}
void Car::releaseAccelerate() {
    // moverRect.y = moverRect.y - 1;
}
void Car::releaseBreak() {}
void Car::straighten() {
    // angle -= 5;
}