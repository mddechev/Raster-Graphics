#include "../../include/commands/RotateCommand.hpp"
#include "../../include/utils/Constants.hpp"

RotateCommand::RotateCommand(SessionEditor* editor_ptr)
    : Command(constants::ROTATE_COMMAND_NAME, editor_ptr) {}

bool RotateCommand::execute(const std::vector<std::string>& tokenized_command) {

    if (!validate(tokenized_command)) {
        std::cerr << "Invalid rotate command: rotate <left/right>" << '\n';
        return false;
    }


    try {
            std::string direction = tokenized_command[1];

        if (direction == constants::ROTATE_LEFT_DIRECTION) {
            get_editor_ptr()->rotate_left();

        } else if (direction == constants::ROTATE_RIGHT_DIRECTION) {
            get_editor_ptr()->rotate_right();
        }

        std::cout << "Rotation " << direction << " applied to session with ID: " << get_editor_ptr()->get_current_session_id() << '\n';

        return true;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return false;
    }
}

bool RotateCommand::validate(const std::vector<std::string>& tokenized_command) {

    if (tokenized_command.size() != 2 || tokenized_command[0] != constants::ROTATE_COMMAND_NAME || !helpers::is_valid_rotation_direction(tokenized_command[1])) {
        return false;
    }

    return true;
}