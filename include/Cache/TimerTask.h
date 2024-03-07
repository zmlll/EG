#ifndef TIMERTASK_H
#define TIMERTASK_H


class TimerTask
{
public:
    virtual ~TimerTask() {}
    virtual void process() =0;

};

#endif