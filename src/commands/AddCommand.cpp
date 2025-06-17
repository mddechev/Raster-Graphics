#include "../../include/commands/AddCommand.hpp"
#include "../../include/utils/Constants.hpp"
#include "../../include/image/ImageFactory.hpp"

AddCommand::AddCommand(SessionEditor* editor)
    : Command(constants::ADD_COMMAND_NAME, editor) {}

bool AddCommand::execute(const std::vector<std::string> &tokenized_command) {

    if (!validate(tokenized_command)) {
        std::cerr << "Invalid add command: add <file_path>" << '\n';
        return false;
    }

    try {
        get_editor_ptr()->add_image(ImageFactory::create_image(tokenized_command[1]));
        std::cout << tokenized_command[1] << " added to session with ID: " << get_editor_ptr()->get_current_session_id() << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return false;
    }
    return true;
}

bool AddCommand::validate(const std::vector<std::string> &tokenized_command) {

    if (tokenized_command.size() != 2 || tokenized_command[0] != constants::ADD_COMMAND_NAME) {
        return false;
    }

    return true;
}