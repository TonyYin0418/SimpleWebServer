#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

int main()
{
    // 0. Initialize network environment
    signal(SIGPIPE, SIG_IGN); // Ignore broken pipe signal

    // 1. Create client handle (socket)
    int sockClient = socket(AF_INET, SOCK_STREAM, 0);

    if (sockClient == -1)
    {
        perror("Failed to create client handle");
        return -1;
    }
    printf("1. Client handle created successfully\n");

    // 2. Connect to server port number and IP address

    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9870);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP address 
    int ret = connect(sockClient, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));

    if (ret == -1)
    {
        perror("Failed to connect to server");
        return -1;
    }

    while (1)
    {
        char buf[1024] = { 0 };
        printf("Enter characters: ");
        // Read a line from the console
        fgets(buf, sizeof(buf), stdin);  // INFO 较旧的 gcc 不支持 gets_s()。
        // 3. Send data to server
        int retSend = send(sockClient, buf, strlen(buf), 0);
        if (retSend == -1)
        {
            perror("Failed to send data to server");
            break;
        }
        // 4. Receive data from server

        char szRecv[4096] = {};
        int retRecv = recv(sockClient, szRecv, 4096, 0);
        if (retRecv <= 0)
        {
            if (retRecv == 0)
                printf("Server closed the connection\n");
            else
                perror("Failed to receive data from server");
            break;
        }
        printf("Received data from server: %s\n", szRecv);
    }

    // 5. Close client handle
    close(sockClient);

    return 0;
}