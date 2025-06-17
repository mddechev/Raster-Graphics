#include "../../include/commands/GrayscaleCommand.hpp"
#include "../../include/utils/Constants.hpp"

GrayscaleCommand::GrayscaleCommand(SessionEditor* editor) 
    : Command(constants::GRAYSCALE_COMMAND_NAME, editor) {}

bool GrayscaleCommand::execute(const std::vector<std::string> &tokenized_command) {

    if (!validate(tokenized_command)) {
        std::cerr << "Invalid grayscale command: grayscale" << '\n';
        return false;
    }

    try {
        get_editor_ptr()->grayscale();
        std::cout << "Grayscale applied to Session with ID: " << get_editor_ptr()->get_current_session_id() << '\n';
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return false;
    }
}

bool GrayscaleCommand::validate(const std::vector<std::string> &tokenized_command) {
    if (tokenized_command.size() != 1 || tokenized_command[0] != constants::GRAYSCALE_COMMAND_NAME) {
        return false;
    }

    return true;
}