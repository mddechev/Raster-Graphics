#include "../../../include/image/types/PPMImage.hpp"

PPMImage::PPMImage(const std::string& file_name, uint16_t width, uint16_t height, uint16_t max_color)
    : Image(file_name, constants::PPM_MAGIC_NUMBER, width, height, max_color), data(height, width) {}

void PPMImage::load(std::istream& in) {

    std::string magic_number;
    in >> magic_number;

    if (magic_number != constants::PPM_MAGIC_NUMBER) {
        throw std::runtime_error("Invalid PPM magic number: " + magic_number);
    }
    set_magic_number(magic_number);

    uint16_t width, height;
    in >> width >> height;

    if (width <= 0 || height <= 0) {
        throw std::runtime_error("Invalid width or height: " + std::to_string(width) + " " + std::to_string(height));
    }
    set_width(width);
    set_height(height);

    uint16_t max_color;
    in >> max_color;
    set_max_color(max_color);
    
    data.resize(get_height(), get_width());
    data.read(in);
}

Image* PPMImage::clone() const {
    return new PPMImage(*this);
}

void PPMImage::print(std::ostream& out) const {

    out << get_magic_number() << '\n';
    out << get_width() << ' ' << get_height() << '\n';
    out << get_max_color() << '\n';

    for (size_t i = 0; i < get_height(); i++) {
        for (size_t j = 0; j < get_width(); j++) {
            data[i][j].print(out);
        }
        out << '\n';
    }
    out << std::endl;
}

void PPMImage::grayscale() {
    
    for (size_t i = 0; i < get_height(); i++) {
        for (size_t j = 0; j < get_width(); j++) {
            data[i][j].to_grayscale();
        }
    }
}

void PPMImage::monochrome() {
    for (size_t i = 0; i < get_height(); i++) {
        for (size_t j = 0; j < get_width(); j++) {
            data[i][j].to_monochrome(get_max_color());
        }
    }
}

void PPMImage::negative() {
    
    for (size_t i = 0; i < get_height(); i++) {
        for (size_t j = 0; j < get_width(); j++) {
            data[i][j].to_negative(get_max_color());
        }
    }
}

void PPMImage::rotate_left() {
    data.rotate_left();
}

void PPMImage::rotate_right() {
    data.rotate_right();
}