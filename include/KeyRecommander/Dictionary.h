#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include <string>
#include <map>
#include <set>  
using namespace std;

class Dictionary
{

private:

    //词典
    vector<pair<string,int>>  _dict;
    
    //索引表
    map<string,set<int>> _indexTable;

public:

    static Dictionary * createInstance();
    //通过词典文件路径初始化词典
    void init(const string& dictpath);
    //获取词典
    vector<pair<string,int>>& getDict();
    //获取索引表
    map<string,set<int>>& getIndexTable();
    //执行查询
    string doQuery(string word);














};





















#endif