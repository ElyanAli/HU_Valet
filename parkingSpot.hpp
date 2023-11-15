#include <iostream>
#include "objects.hpp"
#include "car.hpp"
using namespace std;

class parkingSpot{
    private:
        bool parked;
        int xStart;
        int xEnd;
        int yStart;
        int yEnd;

    public:
        parkingSpot(int, int, int, int);
        bool checkParking(Car&);
};