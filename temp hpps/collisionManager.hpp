#include <iostream>
#include "objects.hpp"


class collisionManager{
    public:
    bool checkCollision(Objects* , Objects*);
    void resolveCollision(Objects*);
};