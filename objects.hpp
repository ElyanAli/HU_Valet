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
        virtual int getPositionX() = 0;
        virtual int getPositionY() = 0;
        SDL_Rect getSrcRect();
        SDL_Texture* getImage();

        virtual void setPositionX(int posX) = 0;
        virtual void setPositionY(int posY) = 0;
        void setSrcRect(SDL_Rect srcRect);
        void setImage(SDL_Texture* img);
};