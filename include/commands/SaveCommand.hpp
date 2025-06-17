#ifndef _SAVE_COMMAND_HPP_
#define _SAVE_COMMAND_HPP_

#include "Command.hpp"

class SaveCommand : public Command {
public:
    SaveCommand(SessionEditor* editor);

    bool execute(const std::vector<std::string> &tokenized_command) override;

private:
    bool validate(const std::vector<std::string> &tokenized_command) override;
};

#endif