#ifndef _COMMAND_INTERPRETER_HPP_
#define _COMMAND_INTERPRETER_HPP_

#include "Command.hpp"

class CommandInterpreter {
public:
    CommandInterpreter(SessionEditor* editor_ptr);
    ~CommandInterpreter();

    bool interpret(const std::string& command_name);

private:
    Command* fetch_by_name(const std::string& command_name);

private:
    std::vector<Command*> supported_commands;
};

#endif