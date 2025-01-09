#include "ScoresController.h"

ScoresController::ScoresController(ScoresService &service) : service(service) {}

tuple<string, string, string> ScoresController::getResponse_All()
{
    nlohmann::json jsonData = service.getScoresJson_All();
    map<string, string> placeholders = {{"{{SCORES}}", jsonData.dump()}};
    return make_tuple("200 OK", renderHTML("view/scores.html", placeholders), "text/html");
}

tuple<string, string, string> ScoresController::getResponse_byStu(string stuID)
{
    nlohmann::json jsonData = service.getScoresJson_byStu(stuID);
    map<string, string> placeholders = {{"{{STU_ID}}", stuID}, {"{{SCORES}}", jsonData.dump()}};
    return make_tuple("200 OK", renderHTML("view/student_page.html", placeholders), "text/html");
}

tuple<string, string, string> ScoresController::getResponse_byCourse(string courseID)
{
    nlohmann::json jsonData = service.getScoresJson_byCourse(courseID);
    map<string, string> placeholders = {{"{{COURSE_ID}}", courseID}, {"{{SCORES}}", jsonData.dump()}};
    return make_tuple("200 OK", renderHTML("view/course_page.html", placeholders), "text/html");
}
/*
// 弃用
string ScoresController::getHtmlRows(const nlohmann::json &jsonData)
{
    string rows = "";
    for (auto &score : jsonData) {
        rows = rows + "<tr>" + "<td>" + score["stu_id"].get<string>() + "</td>" + "<td>" +
               score["course_id"].get<string>() + "</td>" + "<td>" + score["score"].get<string>() + "</td>" + "</tr>\n";
    }
    return rows;
}
*/