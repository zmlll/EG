#ifndef CACHETIMERTASK_H
#define CACHETIMERTASK_H

#include "TimerTask.h"

class CacheTimerTask:public TimerTask
{
public:
    virtual ~CacheTimerTask() {}
    void process() override;

};

#endif