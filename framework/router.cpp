#include "router.h"

using namespace std;

Router::Router() {}

void Router::addRouting(string method, string path, CTRL_FUN handler) { 
    if(path.find(":") != string::npos) { // 动态路由
        // 下面的regex(":([^/]+)")是匹配模式，第三个参数"([^/]+)"是把通配符替换成的文本内容
        string regexPath = regex_replace(path, regex(":([^/]+)"), "([^/]+)"); // 将路径中的参数（如 :courseName）替换为文本 ([^/]+) 之后存储。
        dynamicRouteTable[method].push_back({regex(regexPath), handler}); // 存储带有通配符的路径
    }
    else {  // 静态路由
        routeTable[method][path] = handler;
    }
}

tuple<string, string, string> Router::handle(string method, string path) // 通过method和path找到对应的handler，然后执行
{

    // 静
    if (routeTable.count(method)) {
        if (routeTable[method].count(path)) {
            return routeTable[method][path](smatch{});
        }
    }
    // 动
    if(dynamicRouteTable.count(method)) {
        cout << "正在动态解析！！！！！！！！！！！！";
        for(auto& item: dynamicRouteTable[method]) {
            //item.first -> 带路径前缀的匹配模式，item.second -> handler
            smatch match;
            if(regex_match(path, match, item.first)) {
                return item.second(match);
            }
            // regex_match后，match[0]是整个匹配的字符串(==path)，match[1]是第一个括号匹配的字符串，match[2]是第二个括号匹配的字符串
        }
    }
    return {"404 Not Found,", "Resource not found", "text/plain"};

}

