#ifndef STATUS_HPP
#define STATUS_HPP

/**
 * @brief Status codes for the application.
 *
 */
enum STATUS_CODE {
    SUCCESS = 0,
    FAILURE = -1,
    EXCEPTION = 1,
    INVALID_ARGUMENTS = 10,
    SOCKET_CREATE_ERROR = 20,
    SOCKET_BIND_ERROR = 21,
    SOCKET_LISTEN_ERROR = 22,
    SOCKET_ACCEPT_ERROR = 23,
    SOCKET_CONNECT_ERROR = 24,
    SOCKET_SEND_ERROR = 25,
    SOCKET_RECEIVE_ERROR = 26
};

#endif // STATUS_HPP