#include "../../../include/image/types/Image.hpp"

Image::Image(const std::string& file_name, const std::string& magic_number, uint16_t width, uint16_t height, uint16_t max_color)
    : file_name(file_name), width(width), height(height), max_color(max_color) {

    if (!helpers::is_valid_magic_number(magic_number)) {
        throw std::invalid_argument("Invalid magic number");
    }

    this->magic_number = magic_number;
}

void Image::set_magic_number(const std::string& magic_number) {
    this->magic_number = magic_number;
}

void Image::set_width(unsigned width) {
    this->width = width;
}

void Image::set_height(unsigned height) {
    this->height = height;
}

void Image::set_max_color(unsigned max_color) {
    this->max_color = max_color;
}