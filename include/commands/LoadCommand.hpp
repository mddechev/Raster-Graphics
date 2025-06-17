#ifndef _LOAD_COMMAND_HPP_
#define _LOAD_COMMAND_HPP_

#include "Command.hpp"

class LoadCommand : public Command {
public:
    LoadCommand(SessionEditor* editor_ptr);

    bool execute(const std::vector<std::string>& tokenized_command) override;

private:
    bool validate(const std::vector<std::string>& tokenized_command) override;
};

#endif