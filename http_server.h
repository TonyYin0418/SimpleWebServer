//
//  http_server.h
//  main
//
//  Created by TonyYin on 2024/12/4.
//

#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <string>

#include "MyRouter.h"

using namespace std;

class httpServer
{
   public:
    httpServer(string _ip, int _port, MyRouter &_router);
    void run();
    void sendResponse(int clientSock, const std::string &status, const std::string &body,
                      const std::string &contentType = "text/plain");

   private:
    string ip;
    int port;
    MyRouter &router;
    string parseRequestPath(const std::string &request);
    void handleClient(int clientSocket);
    string getContentType(const string &filePath);
    map<string, string> parseQueryParams(const string &path);
};

#endif /* HTTP_SERVER_H */
