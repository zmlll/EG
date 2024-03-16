#ifndef PROTOCOLPARSE_H
#define PROTOCOLPARSE_H
#include "json.h"
#include <string.h>
using namespace std;
using nlohmann::json;
enum
{
    KeyRecommand,
    WebPageSearch
};

//协议解析类
class ProtocolParser
{
public:
    //json转字符串
    static string Json2string(json& j);
    static json doParse(const string& data);
    static json vector2json(vector<string>& s);
    static void json2vector(json& j,vector<string>& v);

};

#endif