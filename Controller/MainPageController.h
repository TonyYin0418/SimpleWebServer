#ifndef MAIN_PAGE_CONTROLLER_H
#define MAIN_PAGE_CONTROLLER_H

#include <iostream>
#include <string>

#include "../framework/controller.h"

using namespace std;

class MainPageController : public Controller
{
   public:
    void f0(string path) override;
};

#endif  // MAIN_PAGE_CONTROLLER_H
