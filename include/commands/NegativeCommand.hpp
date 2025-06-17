#ifndef _NEGATIVE_COMMAND_HPP_
#define _NEGATIVE_COMMAND_HPP_

#include "Command.hpp"

class NegativeCommand : public Command {
public:
    NegativeCommand(SessionEditor* editor);
    bool execute(const std::vector<std::string> &tokenized_command) override;

private:
    bool validate(const std::vector<std::string> &tokenized_command) override;
};


#endif