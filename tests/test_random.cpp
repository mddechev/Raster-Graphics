#include <string>
#include <iostream>
#include "../Utility/Helpers.hpp"

int main() {

    std::string file_name = "../Images/image.pbm";
    std::cout << helpers::parse_file_extension(file_name) << std::endl;
    return 0;
}