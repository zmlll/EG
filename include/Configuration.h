#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <string>
#include <map>
#include <set>

using namespace std;

class Configuration
{
private:
    //配置文件路径
    string filepath_;
    
    //配置文件内容
    map<string,string> configMap_;

    //停用词词集
    set<string> stopWordList_;


public:
    Configuration(const string & filepath);

    //获取存放配置文件内容的map
    map<string,string> & getConfigMap();

    //获取停用词词集
    set<string> getStopWordList();


};















#endif