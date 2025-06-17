#ifndef _SESSION_HPP_
#define _SESSION_HPP_

#include "../utils/Constants.hpp"
#include "../utils/Helpers.hpp"
#include "../image/ImageContainer.hpp"
#include "../image/ImageFactory.hpp"
#include <stack>

class Session {
public:
    Session();

    void load(const std::vector<std::string>& file_paths);
    void add_image(Image* image);
    void grayscale();
    void monochrome();
    void negative();
    void rotate_left();
    void rotate_right();
    void save() ;
    void save_as(const std::vector<std::string>& file_paths);
    void info(std::ostream& out = std::cout) const;
    void close();
    void undo();

    int get_session_id() const { return session_id; }
    static int get_session_counter();

    void print_images() const;

    bool unsaved_changes_left() const { return unsaved_changes.size() != 0; }

    const std::vector<std::string>& get_unsaved_changes() const { return unsaved_changes; }
private:
    void save_image_to_file(Image* image, const std::string& file_path);
    void save_image_to_default_file(Image* image);
    // void set_previous_versions(const ImageContainer& previous_versions);
private:
    static int session_counter;
private:
    int session_id;
    ImageContainer images;
    std::vector<std::string> unsaved_changes;
};

#endif