#include "../../include/commands/MonochromeCommand.hpp"
#include "../../include/utils/Constants.hpp"

MonochromeCommand::MonochromeCommand(SessionEditor* editor)
    : Command(constants::MONOCHROME_COMMAND_NAME, editor) {}

bool MonochromeCommand::execute(const std::vector<std::string> &tokenized_command) {

    if (!validate(tokenized_command)) {
        std::cerr << "Invalid monochrome command: monochrome" << '\n';
        return false;
    }

    try {
        get_editor_ptr()->monochrome();
        std::cout << "Monochrome transformation applied to session with ID: " << get_editor_ptr()->get_current_session_id() << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return false;
    }
    return true;
}

bool MonochromeCommand::validate(const std::vector<std::string> &tokenized_command) {

    if (tokenized_command.size() != 1 || tokenized_command[0] != constants::MONOCHROME_COMMAND_NAME) {
        return false;
    }

    return true;
}