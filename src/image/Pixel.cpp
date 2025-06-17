#include "../../include/image/Pixel.hpp"

Pixel::Pixel(uint16_t r, uint16_t g, uint16_t b) 
    : red(r), green(g), blue(b) {}

void Pixel::print(std::ostream& out) const {

    out << red << " " << green << " " << blue << "\t";
}

void Pixel::set_red(uint16_t red) {
    this->red = red;
}

void Pixel::set_green(uint16_t green) {
    this->green = green;
}

void Pixel::set_blue(uint16_t blue) {
    this->blue = blue;
}

void Pixel::set_rgb(uint16_t r, uint16_t g, uint16_t b) {

    set_red(r);
    set_green(g);
    set_blue(b);
}

void Pixel::to_grayscale() {

    uint16_t grayscale = static_cast<uint16_t>(0.3 * red + 0.59 * green + 0.11 * blue);

    set_rgb(grayscale, grayscale, grayscale);
}

void Pixel::to_monochrome(uint16_t max_value) {
    

    uint16_t grayscale = static_cast<uint16_t>(0.3 * red + 0.59 * green + 0.11 * blue);
    uint16_t threshold = max_value / 2;

    uint16_t new_value = (grayscale >= threshold) ? max_value : 0;

    set_rgb(new_value, new_value, new_value);
}


void Pixel::to_negative(uint16_t value) {

    set_red(value - red);
    set_green(value - green);
    set_blue(value - blue);
}

// bool Pixel::is_grayscale() const {
//     return red == green && green == blue;
// }

std::ostream& operator << (std::ostream& out, const Pixel& pixel) {

    out << pixel.get_red() << ' ' << pixel.get_green() << ' ' << pixel.get_blue();

    return out;
}

std::istream& operator >> (std::istream& in, Pixel& pixel) {

    uint16_t r, g, b;

    in >> r >> g >> b;

    pixel.set_rgb(r, g, b);

    return in;
}