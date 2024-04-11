#ifndef PARSER_HPP
#define PARSER_HPP

#include <map>
#include <string>

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

    std::string git_commit_hash;

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