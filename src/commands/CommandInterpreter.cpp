#include "../../include/commands/CommandInterpreter.hpp"
#include "../../include/utils/Constants.hpp"
#include "../../include/utils/Helpers.hpp"
#include "../../include/commands/LoadCommand.hpp"
#include "../../include/commands/InfoCommand.hpp"
#include "../../include/commands/ExitCommand.hpp"
#include "../../include/commands/SwitchCommand.hpp"
#include "../../include/commands/CloseCommand.hpp"
#include "../../include/commands/GrayscaleCommand.hpp"
#include "../../include/commands/SaveCommand.hpp"
#include "../../include/commands/SaveAsCommand.hpp"
#include "../../include/commands/AddCommand.hpp"
#include "../../include/commands/MonochromeCommand.hpp"
#include "../../include/commands/NegativeCommand.hpp"
#include "../../include/commands/RotateCommand.hpp"

CommandInterpreter::CommandInterpreter(SessionEditor* editor_ptr) {

    Command* supported_commands[constants::SUPPORTED_COMMANDS_COUNT] = {
        new LoadCommand(editor_ptr),
        new InfoCommand(editor_ptr),
        new ExitCommand(editor_ptr),
        new SwitchCommand(editor_ptr),
        new CloseCommand(editor_ptr),
        new GrayscaleCommand(editor_ptr),
        new SaveCommand(editor_ptr),
        new SaveAsCommand(editor_ptr),
        new AddCommand(editor_ptr),
        new MonochromeCommand(editor_ptr),
        new NegativeCommand(editor_ptr),
        new RotateCommand(editor_ptr)
    };

    for (size_t i = 0; i < constants::SUPPORTED_COMMANDS_COUNT; i++) {
        this->supported_commands.push_back(supported_commands[i]);
    }
}

CommandInterpreter::~CommandInterpreter() {
    for (Command* command : supported_commands) {
        delete command;
    }
}   

bool CommandInterpreter::interpret(const std::string& command_line) {

    std::vector<std::string> tokenized_command = helpers::tokenize_line_to_strings(command_line, ' ');

    if (tokenized_command.empty()) {
        return true;
    }

    try {
        Command* cmd = fetch_by_name(tokenized_command[0]);

        if (!cmd) {
            std::cerr << "Command not found: " << tokenized_command[0] << '\n';
            return true;
        }
        
        return cmd->execute(tokenized_command);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught in command execution: " << e.what() << '\n';
        return  true;
    }
}

Command* CommandInterpreter::fetch_by_name(const std::string& command_name) {

    for (size_t i = 0; i < supported_commands.size(); i++) {

        if (supported_commands[i]->get_command_name() == command_name) {
            return supported_commands[i];
        }
    }
    return nullptr;
}