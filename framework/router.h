#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <functional>
#include "controller.h"

using namespace std;

typedef void (Controller::*CTRL_FUN)(string);

class Router
{
   public:
    Router();
    virtual void setupRouting() = 0;
    
   private:
    using CTRL_FUN = std::function<tuple<string, string, string>()>;
    map<string, map<string, CTRL_FUN> > routeTable;


   public:
    void addRouting(string method, string path, CTRL_FUN handler);
    tuple<string, string, string> handle(string method, string path);
};

#endif  // ROUTER_H
