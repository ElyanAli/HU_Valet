#include <iostream>
// #include <SDL.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class Objects{
    protected:
        int positionX;
        int positionY;
        SDL_Rect srcRect;
        SDL_Texture* image;
        SDL_Renderer* renderer;
    public:
        Objects(SDL_Renderer*);
        int getPositionX();
        int getPositionY();
        SDL_Rect* getSrcRect();
        SDL_Texture* getImage();

        virtual void setPositionX(int posX) = 0;
        virtual void setPositionY(int posY) = 0;
        void setSrcRect(SDL_Rect srcRect);
        void setImage(string img);
};