#include "StudentsController.h"

StudentsController::StudentsController(StudentsService &service) : service(service) {}

const string templatePath = "view/students.html";
// const string templatePath = "../../../../../view/students.html";  // For Xcode

tuple<string, string, string> StudentsController::getResponse(const map<string, string> &queryParams)
{
    nlohmann::json jsonData = service.getStudentsJson(queryParams);
    // cout << jsonData.dump(4) << endl;

    map<string, string> placeholders = {
        {"{{RANGE}}", getHtmlRange(jsonData["range"])},
        {"{{STUDENTS}}", getHtmlRows(jsonData["scores"])},
    };
    return make_tuple("200 OK", renderHTML(templatePath, placeholders), "text/html");
}
string StudentsController::getHtmlRange(const nlohmann::json &jsonData)
{
    string range = "All";
    int agefrom = jsonData["agefrom"].get<int>();
    int ageto = jsonData["ageto"].get<int>();
    if(agefrom != -1) {
        range = to_string(agefrom) + " - " + to_string(ageto);
    }
    return range;
}
string StudentsController::getHtmlRows(const nlohmann::json &jsonData)
{
    string rows = "";
    for (auto &student : jsonData) {
        rows = rows + "<tr>" + 
        "<td>" + "<a href='/scorebystudent/" + student["id"].get<string>() + "'>" + student["id"].get<string>() + "</a>" + "</td>" + 
        "<td>" + student["name"].get<string>() + "</td>" + 
        "<td>" + student["age"].get<string>() + "</td>" + 
        "<td>" + student["sex"].get<string>() + "</td>" + 
        "</tr>\n";
    }
    return rows;
}
