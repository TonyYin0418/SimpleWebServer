//
//  controller.h
//  Final
//
//  Created by TonyYin on 2024/12/4.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#define DECLARE_CTRL_FUN(n) \
   public:                  \
    virtual void f##n(string a);
#define IMPLEMENT_CTRL_FUN(className, n, funName) \
    void className::f##n(string a) { funName(a); }
#define REGISTER_CTRL_FUN(method, path, className, n) \
    addRouting(method, path, new className, (CTRL_FUN) & className::f##n);

#include <map>
#include <string>
using namespace std;

class Controller
{
   public:
    string renderHTML(const string &templatePath, map<string, string> &placeHoldersTable);
    virtual void f0(string path) {}
    //    virtual void f1(string path) {}
    //    virtual void f2(string path) {}
    //    virtual void f3(string path) {}
    //    virtual void f4(string path) {}
    //    virtual ~Controller() {}
};

#endif  // CONTROLLER_H
