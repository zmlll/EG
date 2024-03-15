#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include <string>
#include <map>
#include <set>  
#include "../../include/SearchEngineServer/Configuration.h"
using namespace std;
class Dictionary
{
private:
    class AutoRelease
    {
    public:
        ~AutoRelease()
        {
            if(_pdict)
                delete _pdict;
        }
    };
    Dictionary();
    ~Dictionary();
    vector<pair<string,int>> _dict;
    map<string,set<int>> _index;
    static AutoRelease _ar;
    static Dictionary* _pdict;
    static pthread_mutex_t _dmutex;

public:

    static Dictionary * createInstance();
    //通过词典文件路径初始化词典
    void init(const string& dictpath,const string& indexpath);
    //获取词典
    vector<pair<string,int>>& getDict();
    //获取索引表
    map<string,set<int>>& getIndexTable();


};

#endif