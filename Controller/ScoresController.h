#ifndef SCORES_CONTROLLER_H
#define SCORES_CONTROLLER_H

#include <iostream>
#include <string>

#include "../framework/controller.h"
#include "../http_server.h"
#include "../service/ScoresService.h"
using namespace std;

class ScoresController : public Controller
{
public:
    ScoresController(ScoresService &service);
    tuple<string, string, string> getResponse_All();
    tuple<string, string, string> getResponse_byStu(string stuId);
    tuple<string, string, string> getResponse_byCourse(string courseID);
    
private:
    string getHtmlRows(const nlohmann::json &jsonData);
    ScoresService &service;
};

#endif  // SCORES_CONTROLLER_H
