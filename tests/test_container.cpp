#include "../ImageUtility/ImageContainer.hpp"
#include "../ImageUtility/ImageFactory.hpp"
#include <cassert>

void general_test() {

    ImageContainer container(3);

    
    // assert(container[0]->get_file_name() == image->get_file_name());
    // delete image;

    // image = ImageFactory::create_image("../Images/image1.pgm");
    // assert(container.get_size())
    container.add_image(ImageFactory::create_image("../Images/image.pbm"));
    container.add_image(ImageFactory::create_image("../Images/image1.pgm"));
    container.add_image(ImageFactory::create_image("../Images/image2.ppm"));



    container.print();

    Image* image = container.get_image("../Images/image.pbm");
    image->print();

    Image* image2 = container[1];

    image2->print();
    // delete image;
}

void test_copy_constructor() {

    ImageContainer container(3);

    container.add_image(ImageFactory::create_image("../Images/image.pbm"));
    container.add_image(ImageFactory::create_image("../Images/image1.pgm"));
    container.add_image(ImageFactory::create_image("../Images/image2.ppm"));

    std::cout << "container:\n";
    container.print();

    ImageContainer container2(container);

    std::cout << "container2:\n";
    container2.print();

}

void test_copy_assignment() {

    ImageContainer container(2);

    container.add_image(ImageFactory::create_image("../Images/image.pbm"));
    container.add_image(ImageFactory::create_image("../Images/image1.pgm"));

    std::cout << "container:\n";
    container.print();

    std::cout << "container2:\n";
    ImageContainer container2(1);
    container2.add_image(ImageFactory::create_image("../Images/image2.ppm"));
    container2.print();
    container2 = container;

    std::cout << "container2 after assignment:\n";
    container2.print();

}

int main() {
    test_copy_assignment();
    return 0;
}