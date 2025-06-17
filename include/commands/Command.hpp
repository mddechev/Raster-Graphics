#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include "../session/SessionEditor.hpp"

class Command {
public:
    Command(const std::string& command_name, SessionEditor* editor_ptr);

    virtual ~Command() = default;

    const std::string& get_command_name() const { return command_name; }

    virtual bool execute(const std::vector<std::string>& tokenized_command) = 0;

protected:
    SessionEditor* get_editor_ptr() { return editor_ptr; }

private:
    virtual bool validate(const std::vector<std::string>& tokenized_command) = 0;

private:
    std::string command_name;
    SessionEditor* editor_ptr;
};

#endif