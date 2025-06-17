#include "../../../include/image/types/PBMImage.hpp"

PBMImage::PBMImage(const std::string& file_name, uint16_t width, uint16_t height)
     : Image(file_name, "P1", width, height, 1), data(height, width, 0) {}

void PBMImage::load(std::istream& in) {
   
    std::string magic_number;
    in >> magic_number;
   
    if (magic_number != constants::PBM_MAGIC_NUMBER) {
        throw std::runtime_error("Invalid PBM magic number: " + magic_number);
    }
    set_magic_number(magic_number);

    uint16_t width, height;
    in >> width >> height;
    
    if (width <= 0 || height <= 0) {
        throw std::runtime_error("Invalid width or height: " + std::to_string(width) + " " + std::to_string(height));
    }
    set_width(width);
    set_height(height);

    data.resize(get_height(), get_width());
    data.read(in);
}

void PBMImage::print(std::ostream& out) const {
    
    out << get_magic_number() << '\n';
    out << get_width() << " " << get_height() << '\n';
    data.print(out);
}

Image* PBMImage::clone() const {
    return new PBMImage(*this);
}

void PBMImage::grayscale() {
    return;
}

void PBMImage::monochrome() {
    return;
}

void PBMImage::negative() {
    
    Image* previous_version = this->clone();

    for (size_t i = 0; i < get_height(); i++) {
        for (size_t j = 0; j < get_width(); j++) {
            data[i][j] = get_max_color() - data[i][j];
        }
    }
}

void PBMImage::rotate_left() {
    data.rotate_left();
}

void PBMImage::rotate_right() {
    data.rotate_right();
}