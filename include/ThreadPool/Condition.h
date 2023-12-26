#ifndef CONDITION_H
#define CONDITION_H
#include <pthread.h>
#include "MutexLock.h"
class Condition
{

private:
    //词典
    MutexLock& _mutex;
    //本地实例
    pthread_cond_t _cond;

public:
    Condition(MutexLock &mutex);
    ~Condition();
    
    void wait();
    //唤醒
    void notify();
    //唤醒全部
    void notifyall();
};

#endif