#ifndef _EXIT_COMMAND_HPP_
#define _EXIT_COMMAND_HPP_

#include "Command.hpp"

class ExitCommand : public Command {
public:
    ExitCommand(SessionEditor* editor);

    bool execute(const std::vector<std::string> &tokenized_command) override;
private:

    bool validate(const std::vector<std::string> &tokenized_command) override;
};


#endif