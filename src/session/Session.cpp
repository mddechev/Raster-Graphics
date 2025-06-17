#include "../../include/session/Session.hpp"


int Session::session_counter = 0;

int Session::get_session_counter() {
    return session_counter;
}

Session::Session()
    : session_id(++session_counter) {}

void Session::load(const std::vector<std::string>& file_paths) {

    for (size_t i = 0; i < file_paths.size(); i++) {
        Image* image = ImageFactory::create_image(file_paths[i]);
        add_image(image);
    }
}

void Session::add_image(Image* image) {
    images.add_image(image);
}

void Session::save() {

    for (size_t i = 0; i < images.get_size(); i++) {
        save_image_to_default_file(images[i]);
    }
    unsaved_changes.clear();
}

void Session::save_as(const std::vector<std::string>& file_paths) {

    if (file_paths.size() > images.get_size()) {
        throw std::runtime_error("Number of file paths is greater than number of images in session");
    }

    if (file_paths.size() < images.get_size()) {

        for (size_t i = 0; i < file_paths.size(); i++) {
            save_image_to_file(images[i], file_paths[i]);
        }
        for (size_t i = file_paths.size(); i < images.get_size(); i++) {
            save_image_to_default_file(images[i]);
        }
        unsaved_changes.clear();
        return;
    }
    for (size_t i = 0; i < images.get_size(); i++) {
        save_image_to_file(images[i], file_paths[i]);
    }
    unsaved_changes.clear();
}

void Session::close() {
    
    images.free();
    unsaved_changes.clear();
}

void Session::save_image_to_file(Image* image, const std::string& file_path) {

    ImageFactory::write_image(image, file_path);
}

void Session::save_image_to_default_file(Image* image) {

    std::string file_name = helpers::get_file_name_without_extension(image->get_file_name()) + "_modified." + helpers::parse_file_extension(image->get_file_name());

    ImageFactory::write_image(image, file_name);
}

void Session::grayscale() {

    images.grayscale();
    unsaved_changes.push_back("grayscale");
}

void Session::monochrome() {

    images.monochrome();
    unsaved_changes.push_back("monochrome");
}

void Session::negative() {

    images.negative();
    unsaved_changes.push_back("negative");
}

void Session::rotate_left() {

    images.rotate_left();
    unsaved_changes.push_back("rotate_left");
}

void Session::rotate_right() {

    images.rotate_right();
    unsaved_changes.push_back("rotate_right");
}

void Session::info(std::ostream& out) const {

    out << "Files in session with ID " << session_id << ":" << '\n';
    images.print(out);
}

void Session::print_images() const {
    
    for (size_t i = 0; i < images.get_size(); i++) {
        images[i]->print();
    }
}