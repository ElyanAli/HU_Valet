#include "objects.hpp"


class Obstacle: public Objects{
    private:
        string path;
    public:
        Obstacle(SDL_Renderer*, string, SDL_Rect, SDL_Rect);
        void drawObstacle();
        
};