#include <iostream>
#include "objects.hpp"
using namespace std;

class Coins: public Objects {
    private:
        int currentState;
    public:
        Coins();
        void updateSate();
        void collectCoin();
};