#include <iostream>
// #include <SDL.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class Objects{
    protected:
        SDL_Texture* image;
        SDL_Renderer* renderer;
        SDL_Rect srcRect;
        SDL_Rect moverRect;
        SDL_Texture* loadImage(string);
    public:
        Objects();
        Objects(SDL_Renderer*, SDL_Rect, SDL_Rect );
        int getPositionX();
        int getPositionY();
        SDL_Rect* getSrcRect();
        void setImage(string img);
};