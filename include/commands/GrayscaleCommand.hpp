#ifndef _GRAYSCALE_COMMAND_HPP_
#define _GRAYSCALE_COMMAND_HPP_

#include "Command.hpp"

class GrayscaleCommand : public Command {
public:
    GrayscaleCommand(SessionEditor* editor);

    bool execute(const std::vector<std::string> &tokenized_command) override;

private:
    bool validate(const std::vector<std::string> &tokenized_command) override;
};

#endif