#include "objects.cpp"


class Obstacle: public Objects{
    private:
        string path;
    public:
        Obstacle(SDL_Renderer*, string, SDL_Rect, SDL_Rect);
        void loadObstacle();
        
};