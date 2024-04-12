#include <fstream>
#include <filesystem>
#include <ctime>

#include "logger.hpp"

/**
 * @brief Construct a new Logger:: Logger object
 *
 * @param filename Name of the log file.
 */
Logger::Logger(const std::string& filename)
{
    // Check if the logs directory exists, if not create it.
    std::filesystem::path dir("logs");
    if (!std::filesystem::exists(dir)) {
        std::filesystem::create_directory(dir);
    }

    // Initialize the logfile in the logs directory
    log_file.open(dir / filename, std::ios_base::app);
    Logger::log(LogLevel::INFO, "Opening log file.");
}

/**
 * @brief Destroy the Logger object and close the file.
 *
 */
Logger::~Logger() {
    // Close the file when complete.
    if (log_file.is_open()) {
        Logger::log(LogLevel::INFO, "Closing log file.");
        log_file.close();
    }
}

/**
 * @brief Get the current time as a formatted string.
 *
 * @return std::string
 */
std::string Logger::get_time_string() {
    // Get the current time
    std::time_t current_time = std::time(nullptr);
    char time_string[21];
    std::strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", std::localtime(&current_time));

    return time_string;
}

/**
 * @brief Get the current loglevel as a string.
 *
 * @param loglevel
 * @return std::string
 */
std::string Logger::get_loglevel_string(LogLevel loglevel) {
    // Get the log level as a string
    switch (loglevel) {
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}