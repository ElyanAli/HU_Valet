#include <iostream>
// #include <SDL.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class Objects{
    protected:
        int positionX;
        int positionY;
        SDL_Texture* image;
        SDL_Renderer* renderer;
        SDL_Rect srcRect;
    public:
        Objects(SDL_Renderer*);
        int getPositionX();
        int getPositionY();
        SDL_Rect* getSrcRect();
        void setPositionX(int posX) = 0;
        void setPositionY(int posY) = 0;
        void setImage(string img);
};