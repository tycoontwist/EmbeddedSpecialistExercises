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
    std::ofstream log_file;
    std::string get_time_string();
    std::string get_loglevel_string(LogLevel loglevel);
public:
    // Constructor
    Logger(const std::string& filename);

    // Destructor
    ~Logger();

    // Method declarations
    // Note: this is a template so it must be fully defined at instantiation
    template<typename... Args>
    void log(LogLevel loglevel, const std::string& format, Args... args) {
        if (log_file.is_open()) {
            std::string time_string = get_time_string();
            std::string loglevel_string = get_loglevel_string(loglevel);

            // Format the string
            char buffer[256];
            snprintf(buffer, sizeof(buffer), format.c_str(), args...);

            // Log the message to file
            std::string message = buffer;
            log_file << time_string << "\t|\t" << loglevel_string << "\t|\t" << message << std::endl;
        }
    }
};

#endif // LOGGER_HPP