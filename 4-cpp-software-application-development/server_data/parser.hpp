#ifndef PARSER_HPP
#define PARSER_HPP

#include <map>
#include <string>

// Placeholder
#define GIT_VERSION "9622b8ed713f5a90df27a2687463aafc2c9981d1"

enum class COMMANDS {
    HELP,
    QUIT,
    VERSION,
    REJECT
};

class Parser {
private:
    std::map<std::string, COMMANDS> commands_map = {
    {"help", COMMANDS::HELP},
    {"quit", COMMANDS::QUIT},
    {"version", COMMANDS::VERSION}};

    std::string help();
    std::string quit();
    std::string version();
    std::string reject();
public:
    // Constructor
    Parser() {};

    // Method declarations
    std::string parse(const std::string& command);
};

#endif // PARSER_HPP