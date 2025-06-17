#include "../../include/commands/ExitCommand.hpp"
#include "../../include/utils/Constants.hpp"

ExitCommand::ExitCommand(SessionEditor* editor)
    : Command(constants::EXIT_COMMAND_NAME, editor) {}


bool ExitCommand::execute(const std::vector<std::string> &tokenized_command) {

    if (!validate(tokenized_command)) {
        return false;
    }

    if (get_editor_ptr()->unsaved_changes_left()) {
        char user_input;
        std::cout << "Unsaved changes in Session with ID: " << get_editor_ptr()->get_current_session_id() << '\n';
        for (size_t i = 0; i < get_editor_ptr()->get_current_session()->get_unsaved_changes().size(); i++) {
            std::cout << get_editor_ptr()->get_current_session()->get_unsaved_changes()[i] << '\n';
        }
        std::cout << "Do you want to save them? (y/n):";

        while (true) {
            std::cin >> user_input;
            user_input = std::tolower(user_input);

            if (user_input == 'y') {
                return true;
            }
            else if (user_input == 'n') {
                get_editor_ptr()->close();
                std::cout << "Closing without saving" << '\n';
                break;
            }
            else {
                std::cout << "Invalid input. Please enter 'y' or 'n':";
            }
        }
    }

    std::cout << "...Exiting application..." << '\n';
    exit(0);
}   

bool ExitCommand::validate(const std::vector<std::string> &tokenized_command) {
    if ((tokenized_command.size() == 1) && (tokenized_command[0] == get_command_name())) {
        return true;
    }
    return false;
}