#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include "../common/logger.hpp"
#include "../common/status.hpp"

#define MAX_BUFFER_SIZE 64


int main(int argc, char* argv[]) {
    const std::string& client_logname = "client_logs.log";

    Logger& logger = Logger::get_instance(client_logname);
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <socket_path> <command>" << std::endl;
        return static_cast<int>(STATUS_CODE::INVALID_ARGUMENTS);
    }

    // Grab the socket path from the argument
    const char* socket_path = argv[1];
    const char* message = argv[2];

    // Create a new socket
    int client_socket = socket(AF_UNIX, SOCK_STREAM, 0);

    if (client_socket == STATUS_CODE::FAILURE) {
        logger.log(LogLevel::ERROR, "Failed to create socket");
        return static_cast<int>(STATUS_CODE::SOCKET_CREATE_ERROR);
    } else {
        logger.log(LogLevel::INFO, "Socket created successfully");
    }

    // Connect the socket to the specified path
    // UNIX domain socket; communication between processes on the same host
    struct sockaddr_un serverAddr;
    serverAddr.sun_family = AF_UNIX;
    strncpy(serverAddr.sun_path, socket_path, sizeof(serverAddr.sun_path) - 1);

    if (connect(client_socket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        logger.log(LogLevel::ERROR, "Failed to connect to socket %s", socket_path);
        close(client_socket);
        return static_cast<int>(STATUS_CODE::SOCKET_CONNECT_ERROR);
    }

    // Send data to the server
    if (send(client_socket, message, strlen(message), 0) == STATUS_CODE::FAILURE) {
        logger.log(LogLevel::ERROR, "Failed to send command %s data to the server", message);
        close(client_socket);
        return static_cast<int>(STATUS_CODE::SOCKET_SEND_ERROR);
    }

    char buffer [MAX_BUFFER_SIZE] = {0};
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) == STATUS_CODE::FAILURE) {
        logger.log(LogLevel::ERROR, "Failed to receive data from the server");
        close(client_socket);
        return static_cast<int>(STATUS_CODE::SOCKET_RECEIVE_ERROR);
    }

    std::cout << buffer << std::endl;

    // Close the socket
    close(client_socket);

    return static_cast<int>(STATUS_CODE::SUCCESS);
}