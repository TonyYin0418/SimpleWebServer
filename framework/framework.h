#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct HttpRequest {
    string method;
    string path;
    unordered_map<string, string> queryParams;
};

struct HttpResponse {
    int statusCode = 200;
    string contentType = "text/html";
    string body;

    string toString() const {
        return "HTTP/1.1 " + to_string(statusCode) + " OK\r\n" +
               "Content-Type: " + contentType + "\r\n\r\n" +
               body;
    }
};

#endif
