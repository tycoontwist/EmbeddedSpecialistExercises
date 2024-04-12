#include <iostream>
#include <algorithm>

#include "parser.hpp"
#include "../common/status.hpp"

/**
 * Parse the command and return the result.
 *
 * @param command The command to parse.
 * @return The result of the command.
 */
std::string Parser::parse(const std::string& command) {
    // Convert command to lowercase.
    std::string lower_command = command;
    std::transform(lower_command.begin(), lower_command.end(), lower_command.begin(), ::tolower);

    // Default to reject.
    COMMANDS parsed_command = COMMANDS::REJECT;

    // If the command is not found, default to reject.
    auto iterator = commands_map.find(lower_command);
    if (iterator != commands_map.end()) {
        // First is key, second is value.
        parsed_command = iterator->second;
    }

    // Switch on the parsed command.
    switch (parsed_command) {
        case COMMANDS::VERSION:
            return version();
        default:
            return reject();
    }
}

/**
 * Return the git hash version of the server.
 *
 * @return The git hash of the server.
 */
std::string Parser::version() {
    return GIT_HASH;
}

/**
 * Return the reject message.
 *
 * @return The reject message.
 */
std::string Parser::reject() {
    return "REJECTED";
}