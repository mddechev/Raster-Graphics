#ifndef _HELPERS_HPP_
#define _HELPERS_HPP_

#include <cstddef>
#include <string>
#include "Constants.hpp"
#include <iostream>

namespace helpers {

    std::string parse_file_extension(const std::string& file_name);

    bool is_valid_magic_number(const std::string& magic_number);

    std::string get_file_name_without_extension(const std::string& file_name);

    const std::vector<std::string> tokenize_line_to_strings(const std::string& line, char delimiter = ' ');

    bool is_valid_rotation_direction(const std::string& direction);
}


#endif