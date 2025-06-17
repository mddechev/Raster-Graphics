#include "../ImageTypes/PBMImage.hpp"
#include <fstream>
#include <exception>

void test_loading() {

    try {
        
        PBMImage image("image.pbm", 4, 4);
        assert(image.get_height() == 4);
        std::cout << image.get_magic_number() << ' ' << image.get_file_name() << ' ' << image.get_width() << ' ' << image.get_height() << ' ' << image.get_max_color() << '\n';
        // std::ifstream file("image.pbm");
        // image.load(file);

        // std::cout << image.get_magic_number() << ' ' << image.get_width() << ' ' << image.get_height() << '\n';

        // file.close();
        image.print();
    
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_printing() {

    try {
        
        PBMImage image("image.pbm", 4, 4);
        std::ifstream file("Images/image.pbm");
        
        image.load(file);

        image.print();

        file.close();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_printing_into_file() {

    try {
        PBMImage image("image.pbm");
        std::ifstream file("../Images/image.pbm");

        image.load(file);

        std::ofstream out_file("../Images/image_output_test.pbm");
        image.print(out_file);

        file.close();
        out_file.close();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void test_polymorphic_creation() {

    try {
        Image* image = new PBMImage("image.pbm", 4, 4);
        std::ifstream file("../Images/image.pbm");
        image->load(file);

        
        image->print();
        file.close();
        delete image;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
int main() {
    test_polymorphic_creation();
    return 0;
}