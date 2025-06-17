#ifndef _IMAGE_CONTAINER_HPP_
#define _IMAGE_CONTAINER_HPP_


#include "types/Image.hpp"
#include <vector>

class ImageContainer {
public:
    explicit ImageContainer(size_t capacity = 4);
    explicit ImageContainer(const ImageContainer& other);
    ~ImageContainer();

    ImageContainer& operator = (const ImageContainer& other);
    Image* operator [] (size_t index);
    const Image* operator [] (size_t index) const;

    void print(std::ostream& out = std::cout) const;

    void add_image(Image* image);

    void grayscale();
    void monochrome();
    void negative();
    void rotate_left();
    void rotate_right();

    size_t get_size() const { return images.size(); }
    const Image* get_image(const std::string& image_file_name) const;
    Image* get_image(const std::string& image_file_name);

    bool empty() const { return images.empty(); }
    void free();

private:
    void copy_from(const ImageContainer& other);
    void swap_from(ImageContainer& other);
private:
    std::vector<Image*> images;
};

#endif