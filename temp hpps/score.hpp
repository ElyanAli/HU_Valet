#include <iostream>
using namespace std;

class Score: public UI {
    private:
        int currentScore;

    public:
        Score();
        void updateScore();
        void getScore();
};