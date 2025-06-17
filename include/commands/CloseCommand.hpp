#ifndef _CLOSE_COMMAND_HPP_
#define _CLOSE_COMMAND_HPP_

#include "Command.hpp"

class CloseCommand : public Command {
public:
    CloseCommand(SessionEditor* editor);

    bool execute(const std::vector<std::string> &tokenized_command) override;

private:
    bool validate(const std::vector<std::string> &tokenized_command) override;
};

#endif