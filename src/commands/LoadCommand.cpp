#include "../../include/commands/LoadCommand.hpp"
#include "../../include/utils/Constants.hpp"

LoadCommand::LoadCommand(SessionEditor* editor_ptr)
    : Command(constants::LOAD_COMMAND_NAME, editor_ptr) {}
    
bool LoadCommand::execute(const std::vector<std::string>& tokenized_command) {
    
    if (!validate(tokenized_command)) {
        std::cerr << "Invalid load command: load <file1> <file2> ...\n";
        return false;
    }

    std::vector<std::string> file_paths;
    
    try {
        for (size_t i = 1; i < tokenized_command.size(); i++) {
        file_paths.push_back(tokenized_command[i]);
        }

        get_editor_ptr()->load(file_paths);
        std::cout << "Session with ID: " << get_editor_ptr()->get_current_session_id() << " started" << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught in load execution: " << e.what() << '\n';
        return false;
    }
    return true;
}   
bool LoadCommand::validate(const std::vector<std::string>& tokenized_command) {

    if (tokenized_command.size() < 2 || tokenized_command[0] != constants::LOAD_COMMAND_NAME) {
        return false;
    }

    return true;
}