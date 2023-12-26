#ifndef MUTEX_H
#define MUTEX_H
#include <pthread.h>

class MutexLock
{

private:
    //互斥变量
    pthread_mutex_t _mutex;

public:
    MutexLock();
    ~MutexLock();
    void lock();
    void unlock();
    //获取原生互斥锁的地址，有condition对象进行调用
    pthread_mutex_t *getMutexPtr();

};

#endif