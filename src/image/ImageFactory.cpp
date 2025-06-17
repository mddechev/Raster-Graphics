#include "../../include/image/ImageFactory.hpp"

Image* ImageFactory::create_image(const std::string& file_name) {

    std::string extension = helpers::parse_file_extension(file_name);

    if (extension == constants::PBM_EXTENSION) {
        return create_pbm(file_name);
    }

    if (extension == constants::PGM_EXTENSION) {
        return create_pgm(file_name);
    }

    if (extension == constants::PPM_EXTENSION) {
        return create_ppm(file_name);
    }

    return nullptr;
}

void ImageFactory::write_image(Image* image, const std::string& file_destination) {

    std::string extension = helpers::parse_file_extension(file_destination);

    if (extension == constants::PBM_EXTENSION) {
        write_pbm(image, file_destination);
        return;
    }

    if (extension == constants::PGM_EXTENSION) {
        write_pgm(image, file_destination);
        return;
    }

    if (extension == constants::PPM_EXTENSION) {
        write_ppm(image, file_destination);
        return;
    }
}

Image* ImageFactory::create_pbm(const std::string& file_name) {

    std::ifstream file(file_name);
    
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for reading: " << file_name << std::endl;
        return nullptr;
    }

    Image* image = new PBMImage(file_name);
    image->load(file);
    file.close();
    return image;
}

Image* ImageFactory::create_pgm(const std::string& file_name) {

    std::ifstream file(file_name);
    
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for reading: " << file_name << std::endl;
        return nullptr;
    }

    Image* image = new PGMImage(file_name);
    image->load(file);
    file.close();
    return image;
}

Image* ImageFactory::create_ppm(const std::string& file_name) {

    std::ifstream file(file_name);
    
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for reading: " << file_name << std::endl;
        return nullptr;
    }

    Image* image = new PPMImage(file_name);
    image->load(file);
    file.close();
    return image;
}

void ImageFactory::write_pbm(Image* image, const std::string& file_destination) {

    std::ofstream file(file_destination);
    
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for writing: " << file_destination << std::endl;
        return;
    }

    image->print(file);
    file.close();
}

void ImageFactory::write_pgm(Image* image, const std::string& file_destination) {

    std::ofstream file(file_destination);
    
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for writing: " << file_destination << std::endl;
        return;
    }

    image->print(file);
    file.close();
}

void ImageFactory::write_ppm(Image* image, const std::string& file_destination) {

    std::ofstream file(file_destination);
    
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for writing: " << file_destination << std::endl;
        return;
    }

    image->print(file);
    file.close();
}