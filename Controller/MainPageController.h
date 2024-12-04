#ifndef MAIN_PAGE_CONTROLLER_H
#define MAIN_PAGE_CONTROLLER_H

#include "../framework/controller.h"
#include <string>
#include <iostream>

using namespace std;

class MainPageController : public Controller {
public:
    void f0(string path) override;
};

#endif // MAIN_PAGE_CONTROLLER_H
