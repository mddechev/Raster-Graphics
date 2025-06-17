#include "../../include/commands/SaveAsCommand.hpp"
#include "../../include/utils/Constants.hpp"

SaveAsCommand::SaveAsCommand(SessionEditor* editor) 
    : Command(constants::SAVE_AS_COMMAND_NAME, editor) {}


bool SaveAsCommand::execute(const std::vector<std::string> &tokenized_command) {

    if (!validate(tokenized_command)) {
        std::cerr << "Invalid saveas command: saveas <file_path> <file_path> ..." << '\n';
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

        std::vector<std::string> file_paths(tokenized_command.begin() + 1, tokenized_command.end());

        get_editor_ptr()->save_as(file_paths);

        return true;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return false;
    }
}

bool SaveAsCommand::validate(const std::vector<std::string> &tokenized_command) {
    if (tokenized_command.size() < 2 || tokenized_command[0] != constants::SAVE_AS_COMMAND_NAME) {
        return false;
    }

    return true;
}