#ifndef _PIXEL_HPP_
#define _PIXEL_HPP_

#include <iostream>

class Pixel {
public:
    friend std::ostream& operator << (std::ostream& out, const Pixel& pixel);
    friend std::istream& operator >> (std::istream& in, Pixel& pixel);

public:
    Pixel(uint16_t r = 0, uint16_t g = 0, uint16_t b = 0);

    uint16_t get_red() const { return red; }
    uint16_t get_green() const { return green; }
    uint16_t get_blue() const { return blue; }

    void set_red(uint16_t red);
    void set_green(uint16_t green);
    void set_blue(uint16_t blue);
    void set_rgb(uint16_t r, uint16_t g, uint16_t b);

    void to_grayscale();
    void to_monochrome(uint16_t max_color);
    void to_negative(uint16_t value);

    // bool is_grayscale() const;

    void print(std::ostream& out = std::cout) const;
private:
    uint16_t red;
    uint16_t green;
    uint16_t blue;
};

#endif