#ifndef HTTP_H
#define HTTP_H

#include <iostream>
#include <string>
using namespace std;
class Http
{
   public:
    static void sendResponse(const string &content)
    {
        cout << "HTTP/1.1 200 OK\nContent-Type: text/html\n\n" << content << endl;
    }
};

#endif  // HTTP_H
