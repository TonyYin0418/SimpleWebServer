#include "ScoresController.h"

tuple<string, string, string> ScoresController::getResponse_All()
{
    nlohmann::json jsonData = service.getScoresJson_All();
    //    string templatePath = "../view/scores.html"; //For Cmake
    string templatePath = "../../../../../view/scores.html";  // For Xcode
    map<string, string> placeholders = {{"{{SCORE}}", getHtmlRows(jsonData)}};
    return make_tuple("200 OK", renderHTML(templatePath, placeholders), "text/html");
}

tuple<string, string, string> ScoresController::getResponse_byStu(string stuID)
{
    nlohmann::json jsonData = service.getScoresJson_byStu(stuID);
    //    string templatePath = "../view/scores.html"; //For Cmake
    string templatePath = "../../../../../view/scores.html";  // For Xcode
    map<string, string> placeholders = {{"{{SCORE}}", getHtmlRows(jsonData)}};
    return make_tuple("200 OK", renderHTML(templatePath, placeholders), "text/html");
}

tuple<string, string, string> ScoresController::getResponse_byCourse(string courseID)
{
    nlohmann::json jsonData = service.getScoresJson_byCourse(courseID);
    //    string templatePath = "../view/scores.html"; //For Cmake
    string templatePath = "../../../../../view/scores.html";  // For Xcode
    map<string, string> placeholders = {{"{{SCORE}}", getHtmlRows(jsonData)}};
    return make_tuple("200 OK", renderHTML(templatePath, placeholders), "text/html");
}

string ScoresController::getHtmlRows(const nlohmann::json &jsonData)
{
    string rows = "";
    for (auto &score : jsonData) {
        rows = rows + "<tr>" +
               "<td>" + score["stu_id"].get<string>() + "</td>" +
               "<td>" + score["course_id"].get<string>() + "</td>" +
               "<td>" + score["score"].get<string>() + "</td>" +
               "</tr>\n";
    }
    return rows;
}
