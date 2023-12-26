#ifndef PAGELIBPREPROCESSOR_H
#define PAGELIBPREPROCESSOR_H
#include <vector>
#include <map>
#include <unordered_map>
#include "Configuration.h"



using namespace std;


class PageLibPreprocessor
{

private:
    //分词对象
    WordSegmentation _jieba;

    //网页库的容器对象
    vector <WebPage> _pageLib;

    //网页偏移库对象
    unordered_map<int,pair<int,int>> _offetLib;  

    //倒排索引表对象
    unordered_map<string,vector<pair<int,double>>> _invertIndexTable;


public:
    PageLibPreprocessor(Configuration& conf);
    void doProcess();

private:
    //根据配置信息读取网页库和位置偏移库的内容
    void readInfoFromFile();
    //对冗余的网页进行去重
    void cutRedundantPages();
    //创建倒排索引表
    void builInvertIndexTable();
    //将经过预处理后的网页库、位置偏移库和倒排索引表写回到磁盘上
    void storeOnDisk();

};

#endif