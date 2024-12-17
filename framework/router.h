#ifndef ROUTER_H
#define ROUTER_H

#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <tuple>
#include <vector>

#include "controller.h"

using namespace std;

using CTRL_FUN = function<tuple<string, string, string>(const smatch&)>;

class Router
{
   public:
    Router();
    virtual void setupRouting() = 0;

   private:
    map<string, map<string, CTRL_FUN> > routeTable;  // method, path, handler
    map<string, vector<pair<regex, CTRL_FUN> > > dynamicRouteTable;

   public:
    void addRouting(string method, string path, CTRL_FUN handler);
    tuple<string, string, string> handle(string method, string path);
};

#endif  // ROUTER_H
