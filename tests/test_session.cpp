#include "../Session/Session.hpp"
#include "../ImageUtility/ImageFactory.hpp"
#include <cassert>
#include <exception>
#include <iostream>

void test_session_addition() {

    try {
        Session session1;
        session1.add_image(ImageFactory::create_image("../Images/image.pbm"));
        session1.add_image(ImageFactory::create_image("../Images/image1.pgm"));
        session1.add_image(ImageFactory::create_image("../Images/image2.ppm"));
        
        session1.info();

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void test_session_grayscale() {

    try {
        Session session1;
        session1.add_image(ImageFactory::create_image("../Images/image.pbm"));
        session1.add_image(ImageFactory::create_image("../Images/image1.pgm"));
        session1.add_image(ImageFactory::create_image("../Images/image2.ppm"));
        
        std::cout << "Before grayscale:\n";
        session1.print_images();   

        session1.grayscale();

        std::cout << "After grayscale:\n";
        session1.print_images();   


    
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void test_session_monochrome() {
    try {
        Session session1;
        session1.add_image(ImageFactory::create_image("../Images/image.pbm"));
        session1.add_image(ImageFactory::create_image("../Images/image1.pgm"));
        session1.add_image(ImageFactory::create_image("../Images/image2.ppm"));
        
        std::cout << "Before monochrome:\n";
        session1.print_images();   

        session1.monochrome();

        std::cout << "After monochrome:\n";
        session1.print_images();   


    
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void test_seession_save() {
    try {
        Session session1;
        session1.add_image(ImageFactory::create_image("../Images/image.pbm"));
        session1.add_image(ImageFactory::create_image("../Images/image1.pgm"));
        session1.add_image(ImageFactory::create_image("../Images/image2.ppm"));
        
        std::cout << "Before monochrome:\n";
        session1.print_images();   

        session1.monochrome();

        std::cout << "After monochrome:\n";
        session1.print_images();   

        session1.save();

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}   

void test_session_save_as() {
     try {
        Session session1;
        session1.add_image(ImageFactory::create_image("../Images/image.pbm"));
        session1.add_image(ImageFactory::create_image("../Images/image1.pgm"));
        session1.add_image(ImageFactory::create_image("../Images/image2.ppm"));
        
        session1.grayscale();
        
        std::vector<std::string> file_paths;
        file_paths.push_back("../Images/image_grayscale.pbm");
        file_paths.push_back("../Images/image1_grayscale.pgm");
        // file_paths.push_back("../Images/image2_grayscale.ppm");
        
        session1.save_as(file_paths);
        
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void test_load() {
    try {
        
        Session sesh;
        std::vector<std::string> file_paths;
        file_paths.push_back("../Images/image.pbm");
        file_paths.push_back("../Images/image1.pgm");
        file_paths.push_back("../Images/image2.ppm");

        sesh.load(file_paths);

        std::cout << sesh.get_session_counter() << '\n';

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void test_undo() {

    try {
        Session sesh;
        sesh.add_image(ImageFactory::create_image("../Images/image2.ppm"));
        std::cout << "Before grayscale:\n";
        sesh.print_images();

        sesh.grayscale();
        std::cout << "After grayscale:\n";
        sesh.print_images();

        sesh.monochrome();
        std::cout << "After monochrome:\n";
        sesh.print_images();

        sesh.undo();
        std::cout << "After undoing monochrome:\n";
        sesh.print_images();

        sesh.undo();
        std::cout << "After undoing grayscale:\n";
        sesh.print_images();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
int main() {
    test_undo();
    return 0;
}