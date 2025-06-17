#ifndef _INFO_COMMAND_HPP_
#define _INFO_COMMAND_HPP_

#include "Command.hpp"

class InfoCommand : public Command {
public:
    InfoCommand(SessionEditor* editor_ptr);

    bool execute(const std::vector<std::string>& tokenized_command) override;

private:
    bool validate(const std::vector<std::string>& tokenized_command) override;
};

#endif