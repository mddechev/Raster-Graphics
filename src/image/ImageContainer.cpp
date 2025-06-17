#include "../../include/image/ImageContainer.hpp"

ImageContainer::ImageContainer(size_t capacity) {
    images.reserve(capacity);
}

ImageContainer::ImageContainer(const ImageContainer& other) {

    copy_from(other);
}

ImageContainer& ImageContainer::operator = (const ImageContainer& other) {

    if (this == &other) {
        return *this;
    }

    ImageContainer temp(other);
    swap_from(temp);

    return *this;
}


ImageContainer::~ImageContainer() {
    
    free();
}

Image* ImageContainer::operator [] (size_t index) {
    return images[index];
}

const Image* ImageContainer::operator [] (size_t index) const {
    return images[index];
}

void ImageContainer::print(std::ostream& out) const {
    
    for (size_t i = 0; i < images.size(); i++) {
        out << images[i]->get_file_name() << '\n';
    }
    out << std::endl;
}

void ImageContainer::add_image(Image* image) {

    if (image == nullptr) {
        throw std::invalid_argument("Invalid argument: cannot add nullptr to image container");
    }
    
    for (size_t i = 0; i < images.size(); i++) {
        if (images[i]->get_file_name() == image->get_file_name()) {
            std::cout << "Image already exists in the container" << std::endl;
            return;
        }
    }
    images.push_back(image->clone());
}

void ImageContainer::grayscale() {

    for (size_t i = 0; i < images.size(); i++) {
        images[i]->grayscale();
    }
}

void ImageContainer::monochrome() {

    for (size_t i = 0; i < images.size(); i++) {
        images[i]->monochrome();
    }
}

void ImageContainer::negative() {

    for (size_t i = 0; i < images.size(); i++) {
        images[i]->negative();
    }
}

void ImageContainer::rotate_left() {

    for (size_t i = 0; i < images.size(); i++) {
        images[i]->rotate_left();
    }
}

void ImageContainer::rotate_right() {

    for (size_t i = 0; i < images.size(); i++) {
        images[i]->rotate_right();
    }
}

Image* ImageContainer::get_image(const std::string& image_file_name) {

    int index = -1;
    for (int i = 0; i < images.size(); i++) {
        if (images[i]->get_file_name() == image_file_name) {
            index = i;
        }
    }

    if (index == -1) {
        std::cout << "Image: " << image_file_name << " not found in the container" << std::endl;
        return nullptr;
    }
    return images[index];
}

const Image* ImageContainer::get_image(const std::string& image_file_name) const {

    int index = -1;
    for (int i = 0; i < images.size(); i++) {
        if (images[i]->get_file_name() == image_file_name) {
            index = i;
        }
    }

    if (index == -1) {
        std::cout << "Image: " << image_file_name << " not found in the container" << std::endl;
        return nullptr;
    }
    return images[index];
}

void ImageContainer::copy_from(const ImageContainer& other) {

    images.reserve(other.images.capacity());

    for (size_t i = 0; i < other.images.size(); i++) {
        images.push_back(other.images[i]->clone());
    }
}

void ImageContainer::swap_from(ImageContainer& other) {

    std::swap(images, other.images);
}

void ImageContainer::free() {

    for (size_t i = 0; i < images.size(); i++) {
        delete images[i];
    }
    images.clear();
}
