#include <iostream>
// #include "objects.hpp"
using namespace std;

class Car { //inherit from object
    private:
        float acceleration;
        float speed;
        int fuel;
        int collisionState;
        SDL_Rect moverRect;
    public:
        // void moveFront();
        // void moveBack();
        // void moveRight(bool direction);
        // void moveLeft(bool direction);
        // void upState();
        void accelerate();
        void deaccelerate();
        void turnLeft();
        void turnRight();
        void releaseAccelerate();
        void releaseBreak();
        void straighten();

};
