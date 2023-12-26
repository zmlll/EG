#ifndef PAGELIB_H
#define PAGELIB_H
#include<vector>
#include <map>
#include <string>
#include "DirScanner.h"
#include "Configuration.h"
#include "FileProcessor.h"

using namespace std;
class PageLib :FileProcessor
{
private:
    
    //目录扫描对象的引用
    DirScanner & _dirScanner;

    //存放格式化之后的网页的容器
    vector<string> _files;

    //存放每篇文档在网页库的位置信息
    map<int,pair<int,int>> _offsetLib;

public:
    
    PageLib(Configuration &conf,DirScanner &dirScanner,FileProcessor & fileProcessor);

    //创建网页库
    void create();

    //存储网页库和位置偏移库
    void store();













};















#endif