#include "../../../include/image/types/PGMImage.hpp"


PGMImage::PGMImage(const std::string& file_name, uint16_t width, uint16_t height, uint16_t max_color)
     : Image(file_name, "P2", width, height, max_color), data(height, width, 0) {}

void PGMImage::load(std::istream& in) {
   
    std::string magic_number;
    in >> magic_number;
   
    if (magic_number != constants::PGM_MAGIC_NUMBER) {
        throw std::runtime_error("Invalid PGM magic number: " + magic_number);
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

void PGMImage::print(std::ostream& out) const {
    
    out << get_magic_number() << '\n';
    out << get_width() << " " << get_height() << '\n';
    out << get_max_color() << '\n';
    data.print(out);
}

Image* PGMImage::clone() const {
    return new PGMImage(*this);
}

void PGMImage::grayscale() {
    return;
}

void PGMImage::monochrome() {
    
    for (size_t i = 0; i < get_height(); i++) {
        for (size_t j = 0; j < get_width(); j++) {
            // data[i][j] = (data[i][j] > 127) ? 255 : 0;
            data.at(i, j) = get_max_color() * std::round((double)data.at(i, j) / get_max_color());
        }
    }
}

void PGMImage::negative() {
    
    for (size_t i = 0; i < get_height(); i++) {
        for (size_t j = 0; j < get_width(); j++) {
            data.at(i, j) = get_max_color() - data.at(i, j);
        }
    }
}

void PGMImage::rotate_left() {
    data.rotate_left();
}

void PGMImage::rotate_right() {
    data.rotate_right();
}