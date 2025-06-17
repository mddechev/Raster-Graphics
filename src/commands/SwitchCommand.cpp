#include "../../include/commands/SwitchCommand.hpp"
#include "../../include/utils/Constants.hpp"

SwitchCommand::SwitchCommand(SessionEditor* editor)
    : Command(constants::SWITCH_COMMAND_NAME, editor) {}


bool SwitchCommand::execute(const std::vector<std::string> &tokenized_command) {

    if (!validate(tokenized_command)) {
        std::cerr << "Invalid switch command: switch <session id>" << '\n';
        return false;
    }
    
    try {
        get_editor_ptr()->switch_session(std::stoi(tokenized_command[1]));
        std::cout << "Switched to Session with ID: " << tokenized_command[1] << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return false;
    }
    return true;
}

bool SwitchCommand::validate(const std::vector<std::string> &tokenized_command) {
    if (tokenized_command.size() != 2 || tokenized_command[0] != constants::SWITCH_COMMAND_NAME) {
        return false;
    }

    return true;
}