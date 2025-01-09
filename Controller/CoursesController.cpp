#include "CoursesController.h"

CoursesController::CoursesController(CoursesService &service) : service(service) {}

const string templatePath = "view/courses.html";  // For Cmake
// const string templatePath = "../../../../../view/courses.html";  // For Xcode

tuple<string, string, string> CoursesController::getResponse()
{
    nlohmann::json jsonData = service.getCoursesJson();
    map<string, string> placeholders = {{"{{COURSES}}", jsonData.dump()}};
    return make_tuple("200 OK", renderHTML(templatePath, placeholders), "text/html");
}

/*

// 弃用
string CoursesController::getHtmlRows(const nlohmann::json &jsonData)
{
    string rows = "";
    for (auto &course : jsonData) {
        rows = rows + "<tr>" +
               //        "<td><a href='/scorebycourse/" + jsonData["name"].get<string>() + "'>" +
               "<td>" + course["id"].get<string>() + "</td>" + "<td>" + course["name"].get<string>() + "</td>" +
               "<td>" + course["time"].get<string>() + "</td>" + "<td>" + course["location"].get<string>() + "</td>" +
               "<td>" + course["teacher"].get<string>() + "</td>" + "</tr>\n";
    }
    return rows;
}

*/