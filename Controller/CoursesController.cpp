#include "CoursesController.h"

CoursesController::CoursesController(CoursesService &service) : service(service) {}

tuple<string, string, string> CoursesController::getResponse()
{
    nlohmann::json jsonData = service.getCoursesJson();
    //    cout << data << endl;
    //    return make_tuple("200 OK", data, "application/json");

    //    string templatePath = "../view/courses.html"; //For Cmake
    string templatePath = "../../../../../view/courses.html";  // For Xcode
    map<string, string> placeholders = {{"{{COURSES}}", getHtmlRows(jsonData)}};
    return make_tuple("200 OK", renderHTML(templatePath, placeholders), "text/html");
}

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
