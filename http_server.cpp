#include "http_server.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>  // For close

#include <iostream>
#include <string>

#include "MyRouter.h"

using namespace std;

httpServer::httpServer(string _ip, int _port, MyRouter &_router) : ip(_ip), port(_port), router(_router) {}

void httpServer::run()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Failed to create server handle" << endl;
        return;
    }

    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);                    // Port number  host to net short
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Localhost address
    // to check port:     lsof -i :9870

    if (::bind(serverSocket, (sockaddr *)&addr, sizeof(sockaddr_in)) == -1)
    {  //::bind是因为，我引入了std库，会与之冲突，导致随机编译错误。！！！！
        cerr << "Failed to bind port number" << endl;
        close(serverSocket);
        return;
    }

    if (listen(serverSocket, 5) == -1) {
        cerr << "Failed to listen on port number" << endl;
        close(serverSocket);
        return;
    }

    while (true) {
        sockaddr_in clientAddr{};
        socklen_t clientLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientLen);
        if (clientSocket == -1) {
            perror("Accept failed");
            continue;
        }

        handleClient(clientSocket);
        close(clientSocket);
    }
}

void httpServer::handleClient(int clientSocket)
{
    char buffer[1024] = {0};
    ssize_t ret = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (ret <= 0) {
        cerr << "Failed to receive client data" << endl;
        return;
    }

    string request(buffer);
    string method = "GET";
    string path = parseRequestPath(request);
    if (path.empty()) {
        sendResponse(clientSocket, "400 Bad Request", "Invalid HTTP request");
        return;
    }

    // 路由请求
    tuple<string, string, string> result = router.handle(method, path);
    string status = get<0>(result);
    string body = get<1>(result);
    string contentType = get<2>(result);
    sendResponse(clientSocket, status, body, contentType);
}

string httpServer::parseRequestPath(const string &request)
{
    // 解析 GET /path HTTP/1.1
    size_t pos1 = request.find(' ');
    if (pos1 == std::string::npos) return "";  // pos1 == std::string::npos == -1
    size_t pos2 = request.find(' ', pos1 + 1);
    if (pos2 == std::string::npos) return "";  // pos1 == std::string::npos == -1
    return request.substr(pos1 + 1, pos2 - pos1 - 1);
}

void httpServer::sendResponse(int clientSock, const string &status, const string &body, const string &contentType)
{
    std::string response = "HTTP/1.1 " + status +
                           "\r\n"
                           "Content-Length: " +
                           std::to_string(body.size()) + "\r\n" + "Content-Type: " + contentType + "\r\n" +
                           "Connection: close\r\n\r\n" + body;
    send(clientSock, response.c_str(), response.size(), 0);
}
