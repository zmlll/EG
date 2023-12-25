#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#include "MutexLock.hpp"
#include "Task.h"
#include "Condition.hpp"
#include <queue>
#include <string>


using std::queue;
using Elem = function<void()>;

class TaskQueue
{
public:
    TaskQueue(size_t queSize);
    ~TaskQueue();
    bool empty() const;
    bool full() const;
    void push(Elem &&value);
    Elem pop();
    void wakeup();

private:
    size_t _queSize;
    queue<Elem> _que;
    MuteLock _mutex;
    Condition _notEmpty;
    Condition _notFull;
    bool _flag;

};














#endif