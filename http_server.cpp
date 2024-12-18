#include "http_server.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>  // For close

#include <fstream>
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

    // 无效请求
    if (path.empty()) {
        sendResponse(clientSocket, "400 Bad Request", "Invalid HTTP request");
        return;
    }

    // 静态资源请求
    if (path.find("/public/") != string::npos) {
        string filePath = path;
        filePath.erase(0, 1);
        ifstream file(filePath);
        cout << filePath << endl;
        if (file.is_open()) {
            string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            sendResponse(clientSocket, "200 OK", content, getContentType(filePath));
        }
        else {
            cout << "!!!!!\n";
            sendResponse(clientSocket, "404 Not Found", "File not found");
        }
        file.close();
    }

    map<string, string> queryParams = parseQueryParams(request); 
    // 路由请求
    tuple<string, string, string> result = router.handle(method, path, queryParams);
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

string httpServer::getContentType(const string &filePath)  // 给静态资源文件找对应的Content-Type
{
    if (filePath.find(".html") != string::npos) return "text/html";
    if (filePath.find(".css") != string::npos) return "text/css";
    if (filePath.find(".js") != string::npos) return "application/javascript";
    if (filePath.find(".png") != string::npos) return "image/png";
    if (filePath.find(".jpg") != string::npos) return "image/jpeg";
    if (filePath.find(".gif") != string::npos) return "image/gif";
    return "text/plain";
}

map<string, string> httpServer::parseQueryParams(const string &path) { // 解析query parameters，未来可用正则表达式改写
    // 在server中解析query参数（并不影响路由转发），在router中解析path参数（是地址的一部分）
    map<string, string> queryParams;
    size_t pos = path.find('?');
    if(pos != string::npos) {
        size_t start = pos + 1;
        while (start < path.length()) {
            // 找分隔符位置
            size_t end = path.find('&', start);
            if (end == string::npos) end = path.length();
            size_t mid = path.find('=', start);
            if (mid == string::npos || mid >= end) break;
            // 找到了 && 合法
            string key = path.substr(start, mid - start);
            string value = path.substr(mid + 1, end - mid - 1);
            queryParams[key] = value;
            start = end + 1;
        }
    }
    return queryParams;
}