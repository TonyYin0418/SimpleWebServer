#include "ScoresController.h"

ScoresController::ScoresController(ScoresService &service) : service(service) {}

//const string templatePath = "../view/scores.html"; //For Cmake
const string templatePath = "../../../../../view/scores.html";  // For Xcode

tuple<string, string, string> ScoresController::getResponse_All()
{
    nlohmann::json jsonData = service.getScoresJson_All();
    map<string, string> placeholders = {{"{{SCORES}}", getHtmlRows(jsonData)}};
    return make_tuple("200 OK", renderHTML(templatePath, placeholders), "text/html");
}

tuple<string, string, string> ScoresController::getResponse_byStu(string stuID)
{
    nlohmann::json jsonData = service.getScoresJson_byStu(stuID);
    map<string, string> placeholders = {{"{{SCORES}}", getHtmlRows(jsonData)}};
    return make_tuple("200 OK", renderHTML(templatePath, placeholders), "text/html");
}

tuple<string, string, string> ScoresController::getResponse_byCourse(string courseID)
{
    nlohmann::json jsonData = service.getScoresJson_byCourse(courseID);
    map<string, string> placeholders = {{"{{SCORES}}", getHtmlRows(jsonData)}};
    return make_tuple("200 OK", renderHTML(templatePath, placeholders), "text/html");
}

string ScoresController::getHtmlRows(const nlohmann::json &jsonData)
{
    string rows = "";
    for (auto &score : jsonData) {
        rows = rows + "<tr>" + "<td>" + score["stu_id"].get<string>() + "</td>" + "<td>" +
               score["course_id"].get<string>() + "</td>" + "<td>" + score["score"].get<string>() + "</td>" + "</tr>\n";
    }
    return rows;
}
