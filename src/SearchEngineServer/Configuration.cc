#include "../../include/SearchEngineServer/Configuration.h"
#include <fstream>
#include <iostream>

Configuration::Configuration(const std::string &configFilePath)
{

    std::ifstream ifs(configFilePath);
    std::string first,second;
    if(!ifs)
    {
        std::cerr <<configFilePath << "not exist" << std::endl;
    }
    while(ifs >> first >> second)
    {
        _configs.insert({first,second});
    }
    ifs.close();
}

Configuration *Configuration::getInstance()
{
    //静态初始化，仅执行一次
    pthread_once(&_once,init);
    return _pConfig;
}

void Configuration::init()
{
    _pConfig = new Configuration(_configFilePath);
    atexit(destroy);
}

void Configuration::destroy()
{
    if(_pConfig)
    {
        delete _pConfig;
        _pConfig == nullptr;
    }
}

std::map<std::string,std::string> &Configuration::getConfigMap()
{
    return _configs;
}

const std::string &Configuration::operator[](const std::string &key)
{
    return _configs.at(key);
}

unordered_set<string>& Configuration::getStopWordList()
{
    stopWordListInit();
    return _stopWordList;
}

void Configuration::stopWordListInit()
{
    string StopWordFilePath(_configs["stop"]);

    ifstream ifs(StopWordFilePath);
    if(!ifs.is_open())
    {
        cerr <<"StopWordFilePath Open error!" <<endl;
        return;
    }
    ifs.seekg(std::ios_base::beg);
    string stopWord;

    while(getline(ifs,stopWord))
    {
        if(stopWord.back() == '\r')
        {
            stopWord.pop_back();
        }
        _stopWordList.insert(stopWord);
    }
    ifs.close();
}

Configuration *Configuration::_pConfig = nullptr;
pthread_once_t Configuration::_once = PTHREAD_ONCE_INIT;
string Configuration::_configFilePath = "../conf/server.conf";