#ifndef _SWITCH_COMMAND_HPP_
#define _SWITCH_COMMAND_HPP_

#include "Command.hpp"
#include "../utils/Constants.hpp"

class SwitchCommand : public Command {
public:
    SwitchCommand(SessionEditor* editor);

    bool execute(const std::vector<std::string> &tokenized_command) override;
private:
    bool validate(const std::vector<std::string> &tokenized_command) override;
};


#endif