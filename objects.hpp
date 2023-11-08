#include <iostream>
#include <SDL.h>
using namespace std;

class Objects{
    protected:
        int positionX;
        int positionY;
        SDL_Rect srcRect;
        SDL_Texture* image;
    public:
        Objects();
        int getPositionX();
        int getPositionY();
        SDL_Rect getSrcRect();
        SDL_Texture* getImage();

        void setPositionX(int posX);
        void setPositionY(int posY);
        void setSrcRect(SDL_Rect srcRect);
        void setImage(SDL_Texture* img);
};