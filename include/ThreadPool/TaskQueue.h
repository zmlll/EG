#ifndef TASKQUEUE_H
#define TASKQUEUE_H
#include <pthread.h>
#include <mutex>
#include "MutexLock.h"
#include "Condition.h"
#include <queue>
#include "Task.h"
using namespace std;
class TaskQueue
{


private:
    MutexLock _mutex;
    //缓冲区有数据的条件变量
    Condition _notEmpty;
    //缓冲区没有放满数据的条件变量
    Condition _notFull;
    //重定义回调函数的标签
    typedef std::function<void()> ThreadCallback;
    //队列大小
    size_t _size;
    //队列
    queue<Task> _queue;
    //标志位，用于退出pop函数
    bool _flag;
public:
    TaskQueue(int);
    //判断队列是否为空
    void empty();
    //判断队列是否已满
    void full();
    //往缓冲区中添加任务
    void push(Task);
    //从缓冲区中获取任务
    Task pop();
    //唤醒_notEmpty条件变量
    void wakeup();


};

#endif