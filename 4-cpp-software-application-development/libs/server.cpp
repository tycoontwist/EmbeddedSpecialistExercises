#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include "logger.hpp"


int main(int argc, char* argv[]) {
    const std::string& server_logname = "server_logs.log";

    Logger logger = Logger(server_logname);
    // Check if an argument was passed in.
    if (argc != 2) {
        logger.log(LogLevel::INFO, "A message");
        std::cerr << "Usage: " << argv[0] << " <socket_path>" << std::endl;
        return 1;
    }

    const char* socketPath = argv[1];

    // Check if the socket already exists
    if (access(socketPath, F_OK) != -1) {
        std::cerr << "Socket already exists" << std::endl;
        return 1;
    }

    // Create a socket
    int serverSocket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return 1;
    }
    // Bind the socket to the specified path
    sockaddr_un serverAddress;
    serverAddress.sun_family = AF_UNIX;
    strncpy(serverAddress.sun_path, socketPath, sizeof(serverAddress.sun_path) - 1);
    if (bind(serverSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
        std::cerr << "Failed to bind socket to " << socketPath << std::endl;
        close(serverSocket);
        return 1;
    }
    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Failed to listen for connections" << std::endl;
        close(serverSocket);
        return 1;
    }
    std::cout << "Server is listening on " << socketPath << std::endl;
    // Accept incoming connections
    while (true) {
        sockaddr_un clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, reinterpret_cast<sockaddr*>(&clientAddress), &clientAddressLength);
        if (clientSocket == -1) {
            std::cerr << "Failed to accept connection" << std::endl;
            close(serverSocket);
            return 1;
        }
        // Handle the connection
        // ...
        close(clientSocket);
    }
    close(serverSocket);
    return 0;
}