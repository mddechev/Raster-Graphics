#ifndef _MONOCHROME_COMMAND_HPP_
#define _MONOCHROME_COMMAND_HPP_

#include "Command.hpp"

class MonochromeCommand : public Command {
public:
    MonochromeCommand(SessionEditor* editor);
    bool execute(const std::vector<std::string> &tokenized_command) override;

private:
    bool validate(const std::vector<std::string> &tokenized_command) override;
};


#endif