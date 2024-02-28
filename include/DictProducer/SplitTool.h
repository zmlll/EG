#ifndef SPLITTOOL_H
#define SPLITTOOL_H
#include <vector>
#include <string>
#include "lib/cppjieba/include/cppjieba/Jieba.hpp"
#include "Configuration.h"
using namespace std;

// class SplitTool
// {

// public:
//     //构造函数
//     SplitTool();
//     //虚析构函数
//     virtual ~SplitTool();
//     //分词函数，纯虚函数，提供接口
//     virtual vector<string> cut(const string &sentence) = 0;

// };

// class SplitToolJieba
// {
// private:
//     //配置文件路径
//     Configuration &_conf;
// public:
//     //构造函数
//     SplitToolJieba();
//     //虚析构函数
//     virtual ~SplitToolJieba();
//     //分词函数，纯虚函数，提供接口
//     virtual vector<string> cut(const string & sentence) =0;

// };

class SplitTool
{
public:
    //分词函数 虚函数
    virtual vector<string> cut(const string &sentence,vector<string> &vec) =0;
    
    //虚析构函数
    virtual ~SplitTool(){};

};


class Cppjieba:public SplitTool
{
public:
    //静态函数
    static SplitTool *getSplitTool();
    //分词函数
    vector<string> cut(const string &sentence,vector<string> &vec);
    //销毁函数
    static void destroy();

private:
    class AutoRelease
    {
        public:
            ~AutoRelease()
            {
                if(splittool)
                {
                    delete splittool;
                }
            }
    };

private:
    Cppjieba();
    ~Cppjieba(){} map<string,string> &_configs;
    static SplitTool *splittool;
    static pthread_mutex_t _mutex;

};



#endif