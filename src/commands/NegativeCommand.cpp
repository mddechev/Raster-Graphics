#include "../../include/commands/NegativeCommand.hpp"
#include "../../include/utils/Constants.hpp"

NegativeCommand::NegativeCommand(SessionEditor* editor)
    : Command(constants::NEGATIVE_COMMAND_NAME, editor) {}

bool NegativeCommand::execute(const std::vector<std::string> &tokenized_command) {

    if (!validate(tokenized_command)) {
        std::cerr << "Invalid negative command: negative" << '\n';
        return false;
    }

    try {
        get_editor_ptr()->negative();
        std::cout << "Negative transformation applied to session with ID: " << get_editor_ptr()->get_current_session_id() << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return false;
    }
    return true;
}

bool NegativeCommand::validate(const std::vector<std::string> &tokenized_command) {

    if (tokenized_command.size() != 1 || tokenized_command[0] != constants::NEGATIVE_COMMAND_NAME) {
        return false;
    }

    return true;
}