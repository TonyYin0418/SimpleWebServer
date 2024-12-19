#ifndef STUDENTS_CONTROLLER_H
#define STUDENTS_CONTROLLER_H

#include <iostream>
#include <string>

#include "../framework/controller.h"
#include "../http_server.h"
#include "../service/StudentsService.h"
using namespace std;

class StudentsController : public Controller
{
   public:
    StudentsController(StudentsService &service);
    tuple<string, string, string> getResponse(const map<string, string> &queryParams);

   private:
    string getHtmlRange(const nlohmann::json &jsonData);
    string getHtmlRows(const nlohmann::json &jsonData);
    StudentsService &service;
};

#endif  // STUDENTS_CONTROLLER_H
