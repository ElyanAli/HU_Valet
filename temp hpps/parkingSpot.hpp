#include <iostream>
#include "objects.hpp"
#include "car.hpp"
using namespace std;

class parkingSpot: public Objects{
    private:
        bool parked;
    public:
        bool checkParking(Cars&);
};