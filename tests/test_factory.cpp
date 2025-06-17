#include "../ImageUtility/ImageFactory.hpp"

void test_pbm_creation() {

    try {
        Image* image = ImageFactory::create_image("../Images/image.pbm");

        image->print();
        delete image;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_invalid_pbm_creation() {

    try {
        Image* image = ImageFactory::create_image("../Images/image_invalid.pbm");
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_pgm_creation() {

    try {
        Image* image = ImageFactory::create_image("../Images/image1.pgm");
        image->print();
        delete image;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_invalid_pgm_creation() {

    try {
        Image* image = ImageFactory::create_image("../Images/image_invalid.pgm");
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_ppm_creation() {

    try {
        Image* image = ImageFactory::create_image("../Images/image2.ppm");
        image->print();
        delete image;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_invalid_ppm_creation() {

    try {
        Image* image = ImageFactory::create_image("../Images/image_invalid.ppm");
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_pbm_writing() {

    try {
        Image* image = ImageFactory::create_image("../Images/image.pbm");
        ImageFactory::write_image(image, "../Images/image_output.pbm");
        delete image;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_pgm_writing() {

    try {
        Image* image = ImageFactory::create_image("../Images/image1.pgm");
        ImageFactory::write_image(image, "../Images/image1_output.pgm");
        delete image;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_ppm_writing() {   

    try {
        Image* image = ImageFactory::create_image("../Images/image2.ppm");
        ImageFactory::write_image(image, "../Images/image2_output.ppm");
        delete image;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}


int main() {

    test_ppm_writing();
    return 0;
}