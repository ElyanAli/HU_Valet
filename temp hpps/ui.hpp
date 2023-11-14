#include <iostream>
#include "score.hpp"
#include "time.hpp"
#include <SDL.h>

using namespace std;

class UI {
    private:
        Score score;
        Time time;
        SDL_Texture* scoreUI;
        SDL_Texture* timerUI;
    public:
        void updateScoreUI();
        void updateTimerUI();
};