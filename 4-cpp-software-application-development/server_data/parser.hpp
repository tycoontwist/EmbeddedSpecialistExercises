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

    int help();
    int quit();
    int version();
    int reject();
public:
    // Constructor
    Parser() {};

    // Method declarations
    int parse(const std::string& command);
};

#endif // PARSER_HPP