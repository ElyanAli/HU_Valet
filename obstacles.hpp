#include "objects.cpp"


class Obstacles: public Objects{
    private:
        string path;
    public:
        Obstacles(SDL_Renderer*, string, SDL_Rect);
        void loadObstacles();
};