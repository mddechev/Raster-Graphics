#ifndef _ROTATE_COMMAND_HPP_
#define _ROTATE_COMMAND_HPP_

#include "Command.hpp"

class RotateCommand : public Command {
public:
    RotateCommand(SessionEditor* editor_ptr);

    bool execute(const std::vector<std::string>& tokenized_command);

private:
    bool validate(const std::vector<std::string>& tokenized_command);
};

#endif