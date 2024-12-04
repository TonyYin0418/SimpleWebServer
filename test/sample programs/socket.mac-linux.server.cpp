#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> // For close
#include <iostream>
#include <cstring> // For memset

int main()
{
    // 0. Initialize network environment
    // No need to initialize on macOS
    cout << "Network initialized successfully" << endl;

    // 1. Create server handle (socket)
    int sockServer = socket(AF_INET, SOCK_STREAM, 0);
    if (sockServer == -1)
    {
        cerr << "Failed to create server handle" << endl;
        return -1;
    }
    cout << "1. Server created successfully" << endl;

    // 2. Bind port number and IP address
    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9870); // Port number  host to net short
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");   // Localhost address
    if (bind(sockServer, (sockaddr*)&addr, sizeof(sockaddr_in)) == -1)
    {
        cerr << "Failed to bind port number" << endl;
        close(sockServer);
        return -1;
    }
    cout << "2. Port number bound successfully" << endl;

    // 3. Listen on port number (inform the operating system to establish a logical association with the current program)
    if (listen(sockServer, 5) == -1)
    {
        cerr << "Failed to listen on port number" << endl;
        close(sockServer);
        return -1;
    }
    cout << "3. Listening on port number successfully" << endl;

    while (true)
    {
        // 4. Accept client connection (a new socket will be established as the client's identifier)
        cout << "4. Preparing to wait for client" << endl;
        sockaddr_in clientAddr = {};
        socklen_t nAddrLen = sizeof(sockaddr_in);
        int sockClient = accept(sockServer, (sockaddr*)&clientAddr, &nAddrLen);

        if (sockClient == -1)
        {
            cerr << "Failed to accept client connection" << endl;
            continue; // Continue waiting for the next client after error handling
        }
        cout << "4. Client connection accepted successfully" << endl;

        // Communication loop with the client
        while (true)
        {
            char szData[1024] = {};
            ssize_t ret = recv(sockClient, szData, sizeof(szData) - 1, 0);

            if (ret > 0)
            {
                szData[ret] = '\0'; // Add string terminator
                cout << "5. Received client data successfully [" << szData << "]" << endl;

                // Send echo data
                ret = send(sockClient, szData, ret, 0);
                if (ret == -1)
                {
                    cerr << "Failed to send data" << endl;
                    break; // Disconnect from the client after sending failure
                }
            }
            else if (ret == 0) // Client closed the connection
            {
                cout << "Client has disconnected." << endl;
                break; // Exit the loop normally, prepare to handle the next client
            }
            else // An error occurred
            {
                cerr << "Failed to receive client data" << endl;
                break; // Disconnect after error handling
            }
        }

        // Close client socket
        close(sockClient);
        cout << "Current client disconnected, waiting for the next client..." << endl;
    }

    // After the main loop, close the server socket
    close(sockServer);
    cout << "Resources cleaned up" << endl;
    return 0;
}
