#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <string>


enum LogLevel {
        INFO,
        WARNING,
        ERROR
};

class Logger {

private:
    std::ofstream fname;
public:
    // Constructor
    Logger(const std::string& filename);

    // Destructor
    ~Logger();

    // Function declarations
    void log(LogLevel level, const std::string& message);
};

#endif // LOGGER_HPP