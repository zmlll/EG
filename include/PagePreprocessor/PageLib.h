#ifndef PAGELIB_H
#define PAGELIB_H
#include <vector>
using namespace std;
#include <string>

class PageLib
{

public:
    //构造函数
    PageLib(Configuration & conf,
            DirScanner& dirScanner,
            FileProcessor & fileProcessor);

    //创建网页库
    void create();

    //存储网页库和位置偏移库
    void store();




private:
    DirScanner & _dirScanner;
    vector<string> _files;




};





















#endif