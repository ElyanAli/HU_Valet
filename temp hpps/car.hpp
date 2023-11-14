#include <iostream>
#include "objects.hpp"
using namespace std;

class Cars: public Objects{
    private:
        float acceleration;
        float speed;
        int fuel;
        int collisionState;
        SDL_Rect moverRect;
    public:
        void moveFront();
        void moveBack();
        void moveRight(bool direction);
        void moveLeft(bool direction);
        void upState();

};
