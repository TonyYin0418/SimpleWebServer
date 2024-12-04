#include "router.framework.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Controller::f0(string path) {}
void Controller::f1(string path) {}
void Controller::f2(string path) {}
void Controller::f3(string path) {}
void Controller::f4(string path) {}

Router *thisRouter;

Router::Router()
{
    thisRouter = this;
}

void Router::addRouting(string method, string path, Controller *obj, CTRL_FUN fun)
{
    RoutingElement ele;
    ele.method = method;
    ele.path = path;
    ele.object = obj;
    ele.fun = fun;
    table.push_back(ele);
}

void Router::handle(string method, string path)
{
    for (int i = 0; i < table.size(); i++)
    {
        if (table[i].method == method && table[i].path == path)
        {
            ((*table[i].object).*(table[i].fun))(path);
            break;
        }
    }
}

int main()
{
    thisRouter->setupRouting();
    // test
    thisRouter->handle("GET", "/students/getall");
    thisRouter->handle("GET", "/courses/physics");
    thisRouter->handle("GET", "/students/getbyage");

    return 0;
}
