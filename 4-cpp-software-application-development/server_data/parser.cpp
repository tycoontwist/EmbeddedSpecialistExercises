#include <iostream>
#include <algorithm>

#include "parser.hpp"
#include "../common/status.hpp"


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
        case COMMANDS::HELP:
            return help();
        case COMMANDS::QUIT:
            return quit();
        case COMMANDS::VERSION:
            return version();
        default:
            return reject();
    }
}


std::string Parser::help() {
    return "Help: Display help information";
}

std::string Parser::quit() {
    return "Quit: Exit the program";
}

std::string Parser::version() {
    return GIT_VERSION;
}

std::string Parser::reject() {
    return "REJECTED";
}