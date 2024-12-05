#ifndef ROUTER_H
#define ROUTER_H

#include "controller.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef void (Controller::*CTRL_FUN)(string);

struct RoutingElement {
  string method;
  string path;
  Controller *object;
  CTRL_FUN fun;
};

class Router {
public:
  Router();
  virtual void setupRouting() = 0;
  bool handle(string method, string path);

private:
  vector<RoutingElement> table;

protected:
  void addRouting(string method, string path, Controller *obj, CTRL_FUN fun);
};

#endif // ROUTER_H
