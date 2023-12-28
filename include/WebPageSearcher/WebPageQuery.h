#ifndef WEBPAGEQUERY_H
#define WEBPAGEQUERY_H

#include "Jieba.hpp"
#include <unordered_map>
#include <string>
#include <vector>
#include "WebPage.h"
using namespace std;


class WebpageQuery
{
private:
    //jieba分词库对象
    WordSegmentation _jieba;

    //网页库
    unordered_map<int,WebPage> _pageLib;

    //偏移库
    unordered_map<int,pair<int,int>> _offsetLib;

    //倒排索引表
    unordered_map<string,set<pair<int,double>>> _invertIndexTable;


public:
    WebpageQuery();
    
    //执行查询，返回结果
    string doQuery(const string& str);

    //加载库文件
    void loadLibrary();

    //计算查询词的权重值
    vector<double> getQueryWordsWeightVector(vector<string> &queryWords);

    //执行查询
    bool executeQuery(const vector<string>& queryWords,vector<pair<int,vector<double>>>& resultVec);

    string createJson(vector<int>& docIdVec,const vector<string>& queryWords);

    string returnNoAnswer();


};



#endif