#ifndef SPLITTOOL_H
#define SPLITTOOL_H
#include <vector>
#include <string>
#include "lib/cppjieba/include/cppjieba/Jieba.hpp"
using namespace std;

class SplitTool
{

public:
    //构造函数
    SplitTool();
    //虚析构函数
    virtual ~SplitTool();
    //分词函数，纯虚函数，提供接口
    virtual vector<string> cut(const string &sentence) = 0;

};

class SplitToolJieba
{
private:
    //配置文件路径
    Configuration &_conf;
public:
    //构造函数
    SplitToolJieba();
    //虚析构函数
    virtual ~SplitToolJieba();
    //分词函数，纯虚函数，提供接口
    virtual vector<string> cut(const string & sentence) =0;




};


#endif