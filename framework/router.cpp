#include "router.h"

using namespace std;

Router::Router() {}

void Router::addRouting(string method, string path, Controller* obj, CTRL_FUN fun) {
    RoutingElement ele{method, path, obj, fun};
    table.push_back(ele);
}

bool Router::handle(string method, string path) {
    for (const auto& route : table) {
        if (route.method == method && route.path == path) {
            ((*route.object).*(route.fun))(path);
            return true;
        }
    }
//    cerr << "404 Not Found: " << method << " " << path << endl;
    return false;
}
