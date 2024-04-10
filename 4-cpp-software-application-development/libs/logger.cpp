#include <fstream>
#include <ctime>

#include "logger.hpp"

// class Logger {

//     void log(LogLevel level, const std::string& message) {
//         // Write to logfile based on loglevel.
//         switch (level) {
//             case INFO:
//                 std::cout << "[INFO] " << message << std::endl;
//                 break;
//             case WARNING:
//                 std::cout << "[WARNING] " << message << std::endl;
//                 break;
//             case ERROR:
//                 std::cout << "[ERROR] " << message << std::endl;
//                 break;
//             default:
//                 std::cout << "[UNKNOWN] " << message << std::endl;
//                 break;
//         }
//     }
// };

Logger::Logger(const std::string& filename)
{
    // Initialize the logfile in the logs directory
    fname.open("logs/" + filename, std::ios_base::app);
}

Logger::~Logger() {
    // Close the file when complete.
    if (fname.is_open()) {
        fname.close();
    }
}

void Logger::log(LogLevel loglevel, const std::string& message) {
    if (fname.is_open()) {
        fname << message << std::endl;
    }
}

// void log(LogLevel level, const std::string& message) {
//     std::ofstream logFile;

//     // Append to the existing logfile
//     logFile.open("log.txt", std::ios_base::app);

//     // Get the current time
//     std::time_t currentTime = std::time(nullptr);
//     char timeString[100];
//     std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));

//     // Write the log message
//     logFile << timeString << ": " << message << std::endl;

//     logFile.close();
// }