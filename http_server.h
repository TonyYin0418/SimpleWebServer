//
//  http_server.h
//  main
//
//  Created by TonyYin on 2024/12/4.
//

#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <string>
using namespace std;

class httpServer {
public:
    httpServer(string ip, int port);
    void run();
private:
    string ip;
    int port;
    void handleClient(int clientSocket);
};

#endif /* HTTP_SERVER_H */
