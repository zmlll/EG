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

class ProtocolParse
{
public:
    static string Json2string(json& j);
    static json doParse(const string& data);
    static json vector2json(vector<string>& s);
    static void json2vector(json& j,vector<string>& v);

};

#endif