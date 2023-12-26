#ifndef DIRSCANNER_H
#define DIRSCANNER_H

#include <vector>
#include <string>
using namespace std;

//目录扫描类，递归扫描

class DirScanner
{
private:
    //存放每个语料文件的绝对路径
    vector<string> _files;

public:
    
    DirScanner();
    
    //重载函数调用运算符，调用traverse函数
    void operator()();
    
    //返回_vecFilesfiles的引用
    vector<string> files();

    //获取某一目录下的所有文件
    void traverse(const string &dirname);

};















#endif