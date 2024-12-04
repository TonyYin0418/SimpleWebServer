#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define DECLARE_CTRL_FUN(n) public: virtual void f##n(string a);
#define IMPLEMENT_CTRL_FUN(className,n,funName) void className::f##n(string a) { funName(a); }
#define REGISTER_CTRL_FUN(method,path,className,n) addRouting(method,path,new className,(CTRL_FUN)&className::f##n);

class Controller
{
public:
    virtual void f0(string path);
    virtual void f1(string path);
    virtual void f2(string path);
    virtual void f3(string path);
    virtual void f4(string path);
};

typedef void (Controller::*CTRL_FUN)(string);

struct RoutingElement
{
    string method;
    string path;
    Controller *object;
    CTRL_FUN fun;
};

class Router
{
public:
    Router();
    virtual void setupRouting() = 0;
    void handle(string method, string path);

private:
    vector<RoutingElement> table;

protected:
    void addRouting(string method, string path, Controller *obj, CTRL_FUN fun);
};
