#include "../../include/commands/Command.hpp"

Command::Command(const std::string& command_name, SessionEditor* editor_ptr)
    : command_name(command_name), editor_ptr(editor_ptr) {}