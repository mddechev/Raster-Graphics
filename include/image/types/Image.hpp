#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

#include <string>
#include <iostream>
#include <stdexcept>
#include "../../utils/Helpers.hpp"

class Image {
public:
    explicit Image(const std::string& file_name, const std::string& magic_number, uint16_t width, uint16_t height, uint16_t max_color);
    
    virtual ~Image() = default;

    Image& operator = (const Image& other);

    virtual Image* clone() const = 0;
    virtual void load(std::istream& in) = 0;
    virtual void grayscale() = 0;
    virtual void monochrome() = 0;
    virtual void negative() = 0;
    virtual void print(std::ostream& out = std::cout) const = 0;
    virtual void rotate_left() = 0;
    virtual void rotate_right() = 0;

    const std::string& get_file_name() const { return file_name; }
    const std::string& get_magic_number() const { return magic_number; }
    uint16_t get_width() const { return width; }
    uint16_t get_height() const { return height; }
    uint16_t get_max_color() const { return max_color; }

protected:
    void set_magic_number(const std::string& magic_number);
    void set_width(unsigned width);
    void set_height(unsigned height);
    void set_max_color(unsigned max_color);
    
private:
    std::string file_name;
    std::string magic_number;
    uint16_t width;
    uint16_t height;
    uint16_t max_color;
};

#endif