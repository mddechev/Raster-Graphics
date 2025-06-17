#ifndef _SESSION_EDITOR_HPP_
#define _SESSION_EDITOR_HPP_

#include "Session.hpp"

class SessionEditor {
public:
    SessionEditor();

    void load(const std::vector<std::string>& file_paths);
    void add_image(Image* image);
    void switch_session(unsigned int session_id);

    void grayscale();
    void monochrome();
    void negative();
    void rotate_left();
    void rotate_right();
    void save();
    void save_as(const std::vector<std::string>& file_paths);
    void info(std::ostream& out = std::cout) const;
    void close();
    // void exit(const char user_input);

    int get_current_session_id() const { return current_session_id; }

    bool unsaved_changes_left() const;
    bool no_active_sessions() const { return current_session_id == -1;}

public:
    Session* get_current_session();
    const Session* get_current_session() const;
    // bool no_active_sessions() const { return current_session_id == -1;}

private:
    std::vector<Session> sessions;
    int current_session_id;
};

#endif