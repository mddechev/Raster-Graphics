#include "../../include/commands/CloseCommand.hpp"
#include "../../include/utils/Constants.hpp"

CloseCommand::CloseCommand(SessionEditor* editor)
    : Command(constants::CLOSE_COMMAND_NAME, editor) {}

bool CloseCommand::execute(const std::vector<std::string> &tokenized_command) {
    
    if (!validate(tokenized_command)) {
        std::cerr << "Invalid close command: close" << '\n';
        return false;
    }

    try {
        if (get_editor_ptr()->no_active_sessions()) {
            std::cout << "No active sessions to close" << '\n';
            return true;
        }
        
        if (get_editor_ptr()->get_current_session()->unsaved_changes_left()) {
            char user_input;
            std::cout << "Unsaved changes in Session with ID: " << get_editor_ptr()->get_current_session_id() << '\n';
            for (size_t i = 0; i < get_editor_ptr()->get_current_session()->get_unsaved_changes().size(); i++) {
                std::cout << get_editor_ptr()->get_current_session()->get_unsaved_changes()[i] << '\n';
            }
            std::cout << "Do you want to save them? (y/n):";

            while (true) {
                std::cin >> user_input;
                std::cin.ignore();

                user_input = std::tolower(user_input);

                if (user_input == 'y') {
                    return true;
                }
                else if (user_input == 'n') {
                    break;
                }
                else {
                    std::cout << "Invalid input. Please enter 'y' or 'n':";
                }
            }
        }
        get_editor_ptr()->close();
        // std::cout << "Session with ID: " << get_editor_ptr()->get_current_session_id() << " closed" << '\n';
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return false;
    }
    return true;
}


bool CloseCommand::validate(const std::vector<std::string> &tokenized_command) {
    if (tokenized_command.size() != 1 || tokenized_command[0] != constants::CLOSE_COMMAND_NAME) {
        return false;
    }

    return true;
}