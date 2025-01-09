#ifndef COURSES_CONTROLLER_H
#define COURSES_CONTROLLER_H

#include <iostream>
#include <string>

#include "../framework/controller.h"
#include "../http_server.h"
#include "../service/CoursesService.h"
using namespace std;

class CoursesController : public Controller
{
   public:
    CoursesController(CoursesService &service);
    tuple<string, string, string> getResponse();

   private:
    CoursesService &service;
};

#endif  // COURSES_CONTROLLER_H
