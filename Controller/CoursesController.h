#ifndef COURSES_CONTROLLER_H
#define COURSES_CONTROLLER_H

#include "../framework/controller.h"
#include <iostream>
#include <string>

using namespace std;

class CoursesController : public Controller {
public:
  void f0(string path) override;
};

#endif // COURSES_CONTROLLER_H
