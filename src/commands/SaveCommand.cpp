#include "../../include/commands/SaveCommand.hpp"
#include "../../include/utils/Constants.hpp"

SaveCommand::SaveCommand(SessionEditor* editor)
    : Command(constants::SAVE_COMMAND_NAME, editor) {}

bool SaveCommand::execute(const std::vector<std::string> &tokenized_command) {

    if (!validate(tokenized_command)) {
        std::cerr << "Invalid save command: save" << '\n';
        return false;
    }

   try {
        if (get_editor_ptr()->no_active_sessions()) {
            std::cout << "No active sessions to save" << '\n';
            return true;
        }

        if (!get_editor_ptr()->unsaved_changes_left()) {
            std::cout << "No unsaved changes to save" << '\n';
            return true;
        }

        get_editor_ptr()->save();
        std::cout << "Session with ID: " << get_editor_ptr()->get_current_session_id() << " saved" << '\n';
        return true;
   } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return false;
   }
}

bool SaveCommand::validate(const std::vector<std::string> &tokenized_command) {
    if (tokenized_command.size() != 1 || tokenized_command[0] != constants::SAVE_COMMAND_NAME) {
        return false;
    }

    return true;
}