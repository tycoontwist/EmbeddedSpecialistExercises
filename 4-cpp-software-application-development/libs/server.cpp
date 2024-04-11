#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include "logger.hpp"
#include "status.hpp"


int main(int argc, char* argv[]) {
    const std::string& server_logname = "server_logs.log";

    Logger logger = Logger(server_logname);
    // Check if an argument was passed in.
    if (argc != 2) {
        logger.log(LogLevel::ERROR, "Missing argument");
        std::cerr << "Usage: " << argv[0] << " <socket_path>" << std::endl;

        return static_cast<int>(STATUS_CODE::INVALID_ARGUMENTS);
    }

    // Grab the socket path from the argument
    const char* socket_path = argv[1];

    // Create a new socket
    int server_socket = socket(AF_UNIX, SOCK_STREAM, 0);

    if (server_socket == STATUS_CODE::FAILURE) {
        logger.log(LogLevel::ERROR, "Failed to create socket");
        return static_cast<int>(STATUS_CODE::SOCKET_CREATE_ERROR);
    } else {
        logger.log(LogLevel::INFO, "Socket created successfully");
    }

    // Bind the socket to the specified path
    // UNIX domain socket; communication between processes on the same host
    sockaddr_un server_address;
    server_address.sun_family = AF_UNIX;

    strncpy(server_address.sun_path, socket_path, sizeof(server_address.sun_path) - 1);
    if (bind(server_socket, reinterpret_cast<sockaddr*>(&server_address), sizeof(server_address)) == -1) {
        logger.log(LogLevel::ERROR, "Failed to bind socket to %s", socket_path);
        close(server_socket);
        return static_cast<int>(STATUS_CODE::SOCKET_BIND_ERROR);
    } else {
        logger.log(LogLevel::INFO, "Socket bound to %s", socket_path);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) == STATUS_CODE::FAILURE) {
        logger.log(LogLevel::ERROR, "Failed to listen for connections");
        close(server_socket);
        return static_cast<int>(STATUS_CODE::SOCKET_LISTEN_ERROR);
    } else {
        logger.log(LogLevel::INFO, "Listening for connections");
    }

    // Accept incoming connections
    while (true) {
        sockaddr_un client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, reinterpret_cast<sockaddr*>(&client_address), &client_address_length);
        if (client_socket == STATUS_CODE::FAILURE) {
            logger.log(LogLevel::ERROR, "Failed to accept connection");
            close(server_socket);
            return static_cast<int>(STATUS_CODE::SOCKET_ACCEPT_ERROR);
        }
        // Handle the connection
        // TODO: Implement connection handling
        close(client_socket);
    }
    close(server_socket);
    return 0;
}

