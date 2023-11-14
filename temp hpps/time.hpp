#include <iostream>
using namespace std;

class Time: public UI {
    private:
        int timeRemaining;
    public:
    Time();
    void startTimer();
    void updateTimer();
};