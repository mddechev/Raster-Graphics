#include "../ImageTypes/PPMImage.hpp"
#include "../ImageUtility/ImageFactory.hpp"
#include <exception>
#include <fstream>


void test_loading() {

    try {
        PPMImage image("image2.ppm", 4, 4, 15);

        std::ifstream file("Images/image2.ppm");

        image.load(file);
        std::cout << "Image loaded successfully" << std::endl;
        std::cout << "Printing image..." << '\n';

        image.print();

        file.close();
    

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_printing_into_file() {

    try {
        PPMImage image("image2.ppm", 4, 4, 15);
        std::ifstream file("../Images/image2.ppm");
        image.load(file);
        
        std::ofstream out_file("../Images/image2_output_test.ppm");
        image.print(out_file);

        file.close();
        out_file.close();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_polymorphic_creation() {

    try {
        Image* image = new PPMImage("image2.ppm", 4, 4, 15);
        std::ifstream file("../Images/image2.ppm");
        image->load(file);

        image->print();
        file.close();
        delete image;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_monochrome() {
    try {
        Image* image = ImageFactory::create_image("../Images/image3.ppm");

        image->print();
        std::cout << "--------------------------------" << std::endl;
        image->monochrome();
        image->print();

        // std::ofstream out_file("../Images/image3_grayscale.ppm");
        // image.print(out_file);
        delete image;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_grayscale() {
    try {
        Image* image = ImageFactory::create_image("../Images/image3.ppm");

        image->print();
        std::cout << "--------------------------------" << std::endl;
        image->grayscale();
        image->print();

        // std::ofstream out_file("../Images/image3_grayscale.ppm");
        // image.print(out_file);
        delete image;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_negative() {
    try {
        Image* image = ImageFactory::create_image("../Images/image3.ppm");

        image->print();
        std::cout << "--------------------------------" << std::endl;
        image->negative();
        image->print();

        delete image;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    test_negative();
    return 0;
}