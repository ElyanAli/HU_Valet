#include <iostream>
using namespace std;

class Time {
    private:
        int timeRemaining;
    public:
    Time();
    void startTimer();
    void updateTimer();
};