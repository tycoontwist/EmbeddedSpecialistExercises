#ifndef PARSER_HPP
#define PARSER_HPP

#include <map>
#include <string>

// Add more commands here.
enum class COMMANDS {
    VERSION,
    REJECT
};

/**
 * @brief The parser class.
 *
 */
class Parser {
private:
    std::map<std::string, COMMANDS> commands_map = {
    {"version", COMMANDS::VERSION}};

    std::string version();
    std::string reject();
public:
    // Constructor
    Parser() {};

    // Method declarations
    std::string parse(const std::string& command);
};

#endif // PARSER_HPP