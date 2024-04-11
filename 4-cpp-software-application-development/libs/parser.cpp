#include <iostream>
#include <algorithm>

#include "parser.hpp"
#include "status.hpp"


int Parser::parse(const std::string& command) {
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


int Parser::help() {
    std::cout << "Help: Display help information" << std::endl;
    return static_cast<int>(STATUS_CODE::SUCCESS);
}

int Parser::quit() {
    std::cout << "Quit: Exit the program" << std::endl;
    return static_cast<int>(STATUS_CODE::SUCCESS);
}

int Parser::version() {
    std::cout << GIT_VERSION << std::endl;
    return static_cast<int>(STATUS_CODE::SUCCESS);
}

int Parser::reject() {
    std::cout << "REJECTED" << std::endl;
    return static_cast<int>(STATUS_CODE::SUCCESS);
}