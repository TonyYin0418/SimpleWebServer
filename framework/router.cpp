#include "router.h"

using namespace std;

Router::Router() {}

void Router::addRouting(string method, string path, CTRL_FUN handler)
{
    routeTable[method][path] = handler;
}

tuple<string, string, string> Router::handle(string method, string path)
{
    if(routeTable.count(method)) {
        if(routeTable[method].count(path)) {
            return routeTable[method][path]();
        }
    }
    return {"404 Not Found,", "Resource not found", "text/plain"};
}
