#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H
#include <unordered_set>
#include <string.h>
#include <map>
#include <set>
using namespace std;

class Configuration
{
    Configuration(const Configuration &)  = delete;
    Configuration(Configuration &&) = delete;
    Configuration &operator=(const Configuration &) = delete;
    Configuration &operator=(Configuration &&) = delete;

public:
    static Configuration *getInstance();
    //获取配置映射
    std::map<std::string,std::string> &getConfigMap();
    //获取停用词集合内容
    unordered_set<string> &getStopWordList();
    //初始化函数
    static void init();
    //销毁函数
    static void destroy();
    //
    const std::string &operator[](const std::string &key);

private:
    Configuration(const std::string &configFilePath);
    ~Configuration() =default;
    void stopWordListInit();

private:
    static Configuration *_pConfig;
    static pthread_once_t _once;
    static std::string _configFilePath;
    std::map<std::string,std::string> _configs;
    unordered_set<string> _stopWordList;

};
#endif