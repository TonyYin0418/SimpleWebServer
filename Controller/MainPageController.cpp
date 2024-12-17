#include "MainPageController.h"
#include <fstream>
#include <iostream>


tuple<string, string, string> MainPageController::getResponse() {
    //    string templatePath = "../view/index.html"; //For Cmake
    string templatePath = "../../../../../view/index.html";  // For Xcode
   
    ifstream file(templatePath);
    if (!file.is_open()) return make_tuple("404 Not Found", "没打开index.html", "text/plain");;
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    return make_tuple("200 OK", content, "text/html");

}
