#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H
#include "TimerTask.h"
#include <pthread.h>
#include <vector>
using namespace std;

class TimerManager
{
public:
    static TimerManager* getTimerManager();
    static void init();


private:
    TimerManager();
    ~TimerManager(){}

    int createTimerfd();
    void setTimerfd(int delay,int interval);
    void handleRead();

    int _timerfd;
    int _delay;
    int _interval;
    bool _isStarted;

    static TimerManager* _tmanager;
    static pthread_once_t _once;
    vector<TimerTask*> _wheelList;
    

};

#endif