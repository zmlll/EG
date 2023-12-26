#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <vector>
#include "Thread.h"
#include <functional>
#include <memory>
using namespace std;

class ThreadPool
{

private:
    //Linux下的线程类型
    int _threadNum;

    //线程对象的容器
    vector<Thread*> _vecThreads;

    //缓冲区大小
    int _bufSize;

    //缓冲区对象
    buffer _buf;
public:
    //重定义回调函数的标签
    typedef function<void()> Task;

    //线程池开始执行
    void start();
    //停止线程池
    void stop();
    //往线程池中添加任务
    void addTask();
    //线程池中每个线程的函数执行体
    void threadFunc();
private:
    //从缓冲区中获取任务
    Task getTask();

};

#endif