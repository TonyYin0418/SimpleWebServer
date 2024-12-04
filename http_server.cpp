#include "http_server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> // For close
#include <iostream>
#include <string>  //For memset

using namespace std;

httpServer::httpServer(string _ip, int _port) : ip(_ip), port(_port) {}

void httpServer::run()
{
    int sockServer = socket(AF_INET, SOCK_STREAM, 0);
    if (sockServer == -1)
    {
        cerr << "Failed to create server handle" << endl;
        return;
    }

    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);                   // Port number  host to net short
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost address

    if (bind(sockServer, (sockaddr *)&addr, sizeof(sockaddr_in)) == -1)
    {
        cerr << "Failed to bind port number" << endl;
        close(sockServer);
        return;
    }

    if (listen(sockServer, 5) == -1)
    {
        cerr << "Failed to listen on port number" << endl;
        close(sockServer);
        return;
    }

    while (true)
    {
        // Accept client connection (a new socket will be established as the client's identifier)
        cout << "Preparing to wait for client" << endl;
        sockaddr_in clientAddr = {};
        socklen_t nAddrLen = sizeof(sockaddr_in);
        int sockClient = accept(sockServer, (sockaddr *)&clientAddr, &nAddrLen);

        if (sockClient == -1)
        {
            cerr << "Failed to accept client connection" << endl;
            continue; // Continue waiting for the next client after error handling
        }
        cout << "Client connection accepted successfully" << endl;

        // Communication loop with the client
        while (true)
        {
            sockaddr_in clientAddr{};
            socklen_t clientLen = sizeof(clientAddr);
            int clientSocket = accept(sockServer, (struct sockaddr *)&clientAddr, &clientLen);
            if (clientSocket == -1)
            {
                perror("Accept failed");
                continue;
            }

            handleClient(clientSocket);
        }
    }
}

void httpServer::handleClient(int clientSocket) {
    const char *httpResponse =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 13\r\n"
        "\r\n"
        "Hello, world";

    send(clientSocket, httpResponse, strlen(httpResponse), 0);
    close(clientSocket);
}
