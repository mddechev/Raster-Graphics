#ifndef _SAVE_AS_COMMAND_HPP_
#define _SAVE_AS_COMMAND_HPP_

#include "Command.hpp"

class SaveAsCommand : public Command {
public:
    SaveAsCommand(SessionEditor* editor);

    bool execute(const std::vector<std::string> &tokenized_command) override;

private:
    bool validate(const std::vector<std::string> &tokenized_command) override;
};


#endif