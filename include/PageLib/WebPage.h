#ifndef WEBPAGE_H
#define WEBPAGE_H
#include <string>
#include <vector>
#include <map>
#include <set>
#include "PageLibPreprocessor.h"
using namespace std;



class WebPage:PageLibPreprocessor
{
    const static int TOPK_NUMBER =20; 

    //判断两篇文档是否相等
    friend bool operator==(const WebPage &lhs,const WebPage &rhs);
    
    //对文档按Docid进行排序
    friend bool operator<(const WebPage &lhs,const WebPage &rhs);

private:
    //整篇文档，包含xml在内
    string _doc;

    //文档id
    int _docId;

    //文档标题
    string _docTitle;

    //文档URL
    string _docUrl;

    //文档内容
    string _docContent;

    //文档摘要，需自动生成，不是固定的
    string _docSummary;

    //词频最高的前20个词
    vector<string> _topWords;

    //保存每篇文档的所有词语和词频，不包括停用词
    map<string,int> _wordsMap;


public:

    WebPage(string &doc,Configuration & config,WordSegmentation & jieba);

    //获取文档的docid
    int getDocId();

    //获取文档
    string getDoc();

    //获取文档的词频统计map
    map<string,int> & getWordsMap();

    //对格式化文档进行处理
    void processDoc(const string &doc,Configuration & config,WordSegmentation &);

    //求取文档的topK词集
    void calcTopK(vector<string> &wordsVec,int k,set<string> & stopWordList);





    







};














#endif