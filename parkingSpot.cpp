#include "ParkingSpot.hpp"

ParkingSpot::ParkingSpot(SDL_Renderer* rndr, SDL_Rect srct, SDL_Rect mrct, string pth): Objects(rndr, srct, mrct){
    path = pth;
    image = loadImage(path);
}
