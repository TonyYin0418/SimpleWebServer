#ifndef COURSES_CONTROLLER_H
#define COURSES_CONTROLLER_H

#include <iostream>
#include <string>

#include "../framework/controller.h"

using namespace std;

class CoursesController : public Controller
{
   public:
    void f0(string path) override;
};

#endif  // COURSES_CONTROLLER_H
