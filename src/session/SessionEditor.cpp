#include "../../include/session/SessionEditor.hpp"


SessionEditor::SessionEditor() 
    : current_session_id(-1) {}


void SessionEditor::load(const std::vector<std::string>& file_paths) {
    
    Session new_session;
    new_session.load(file_paths);
    sessions.push_back(new_session);
    current_session_id = new_session.get_session_id();
}

void SessionEditor::add_image(Image* image) {

    if (no_active_sessions()) {
        throw std::runtime_error("No active session loaded to add image");
    }

    get_current_session()->add_image(image);
}

void SessionEditor::switch_session(unsigned int session_id) {

    for (size_t i = 0; i < sessions.size(); i++) {
        
        if (sessions[i].get_session_id() == session_id) {
            current_session_id = session_id;
            return;
        }
    }
    throw std::runtime_error("Session with ID " + std::to_string(session_id) + " not found");
}

void SessionEditor::grayscale() {

    if (no_active_sessions()) {
        throw std::runtime_error("No active session loaded to apply grayscale transformation");
    }

    get_current_session()->grayscale();
}

void SessionEditor::monochrome() {

    if (no_active_sessions()) {
        throw std::runtime_error("No active session loaded to apply monochrome transformation");
    }

    get_current_session()->monochrome();
}

void SessionEditor::negative() {

    if (no_active_sessions()) {
        throw std::runtime_error("No active session loaded to apply negative transformation");
    }

    get_current_session()->negative();
}

void SessionEditor::rotate_left() {

    if (no_active_sessions()) {
        throw std::runtime_error("No active session loaded to rotate left");
    }

    get_current_session()->rotate_left();
}

void SessionEditor::rotate_right() {

    if (no_active_sessions()) {
        throw std::runtime_error("No active session loaded to rotate right");
    }

    get_current_session()->rotate_right();
}

void SessionEditor::save() {

    if (no_active_sessions()) {
        throw std::runtime_error("No active session loaded to save");
    }

    get_current_session()->save();
}

void SessionEditor::save_as(const std::vector<std::string>& file_paths) {

    if (no_active_sessions()) {
        throw std::runtime_error("No active session loaded to save as");
    }

    get_current_session()->save_as(file_paths);
}


void SessionEditor::info(std::ostream& out) const {

    if (no_active_sessions()) {
        throw std::runtime_error("No active session loaded to list");
    }
    
    get_current_session()->info(out);
}

void SessionEditor::close() {

    if (no_active_sessions()) {
        throw std::runtime_error("No active session loaded to close");
    }

    get_current_session()->close();
    std::cout << "Session with ID: " << current_session_id << " closed" << '\n';
    sessions.erase(sessions.begin() + current_session_id - 1);

    if (sessions.empty()) {
        current_session_id = -1;
        std::cout << "No active sessions left." << '\n';
        return;
    }
    current_session_id = sessions[0].get_session_id();
    std::cout << "Switched to Session with ID: " << current_session_id << '\n';
}

Session* SessionEditor::get_current_session() {

    for (size_t i = 0; i < sessions.size(); i++) {
        
        if (sessions[i].get_session_id() == current_session_id) {
            return &sessions[i];
        }
    }

    throw std::runtime_error("Session with ID " + std::to_string(current_session_id) + " not found");
}

const Session* SessionEditor::get_current_session() const {

    for (size_t i = 0; i < sessions.size(); i++) {
        
        if (sessions[i].get_session_id() == current_session_id) {
            return &sessions[i];
        }
    }

    throw std::runtime_error("Session with ID " + std::to_string(current_session_id) + " not found");
}

bool SessionEditor::unsaved_changes_left() const {

    for (size_t i = 0; i < sessions.size(); i++) {
        if (sessions[i].unsaved_changes_left()) {
            // std::cout << "Unsaved changes left in session " << sessions[i].get_session_id() << '\n';
            return true;
        }
    }
    return false;
}