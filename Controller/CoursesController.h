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
    //    void f0(string path) override;
    tuple<string, string, string> getResponse();
    string getHtmlRows(const nlohmann::json &jsonData);

   private:
    CoursesService &service;
};

#endif  // COURSES_CONTROLLER_H
