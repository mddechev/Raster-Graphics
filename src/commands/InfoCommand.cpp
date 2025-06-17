#include "../../include/commands/InfoCommand.hpp"
#include "../../include/utils/Constants.hpp"

InfoCommand::InfoCommand(SessionEditor* editor_ptr)
    : Command(constants::INFO_COMMAND_NAME, editor_ptr) {}

bool InfoCommand::execute(const std::vector<std::string>& tokenized_command) {

    if (!validate(tokenized_command)) {
        std::cerr << "Invalid info command: info\n";
        return false;
    }

    try {
        get_editor_ptr()->info(std::cout);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught in info execution: " << e.what() << '\n';
        return false;
    }
    return true;
}

bool InfoCommand::validate(const std::vector<std::string>& tokenized_command) {

    if (tokenized_command.size() != 1 || tokenized_command[0] != constants::INFO_COMMAND_NAME) {
        return false;
    }

    return true;
}