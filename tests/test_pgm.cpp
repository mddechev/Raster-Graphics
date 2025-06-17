#include "../ImageTypes/PGMImage.hpp"
#include <fstream>
#include <exception>
#include <iostream>

void test_loading() {

    try {
        PGMImage image("image1.pgm", 4, 4, 15);
        std::ifstream file("Images/image1.pgm");
        image.load(file);
        image.print();
        file.close();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_printing() {

    try {
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    PGMImage image("image1.pgm", 4, 4, 15);
    std::ifstream file("Images/image1.pgm");
    image.load(file);
    image.print();
    file.close();
}

void test_polymorphic_creation() {

    try {
        Image* image = new PGMImage("image1.pgm", 4, 4, 15);
        std::ifstream file("../Images/image1.pgm");
        image->load(file);

        
        image->print();
        file.close();
        delete image;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    // test_loading();
    test_polymorphic_creation();
    return 0;
}