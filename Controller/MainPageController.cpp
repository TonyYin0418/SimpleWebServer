#include "MainPageController.h"

#include <fstream>
#include <iostream>

// const string templatePath = "../view/index.html"; //For Cmake
const string templatePath = "../../../../../view/index.html";  // For Xcode

tuple<string, string, string> MainPageController::getResponse()
{
    ifstream file(templatePath);
    if (!file.is_open()) return make_tuple("404 Not Found", "没打开index.html", "text/plain");
    ;
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    return make_tuple("200 OK", content, "text/html");
}
