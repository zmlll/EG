#ifndef THREAD_H
#define THREAD_H
#include <thread>
#include <functional>
using namespace std;
class Thread
{
private:
    
    //Linux下的线程类型
    pthread_t _pthId;

    //记录线程是否正在运行
    bool isRunning();

    //重定义回调函数的标签
    typedef function<void()> ThreadCallback;

    //执行任务的函数对象
    ThreadCallback _cb;

public:
    
    Thread(ThreadCallback cb);

    ~Thread();

    //线程开始执行
    void start();

    //等待线程执行完毕
    void join();

private:
    //线程的函数执行体
    static void * threadFunc(void *arg);

};

#endif