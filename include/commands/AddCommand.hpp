#ifndef _ADD_COMMAND_HPP_
#define _ADD_COMMAND_HPP_

#include "Command.hpp"

class AddCommand : public Command {
public:
    AddCommand(SessionEditor* editor);
    bool execute(const std::vector<std::string> &tokenized_command) override;

private:
    bool validate(const std::vector<std::string> &tokenized_command) override;
};

#endif