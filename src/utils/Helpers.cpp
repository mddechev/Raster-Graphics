#include "../../include/utils/Helpers.hpp"

std::string helpers::parse_file_extension(const std::string& file_name) {
    size_t last_dot_index = file_name.find_last_of('.');
    if (last_dot_index == std::string::npos) {
        return "";
    }
        
    return file_name.substr(last_dot_index + 1);
}

bool helpers::is_valid_magic_number(const std::string& magic_number) {

    return magic_number == constants::PBM_MAGIC_NUMBER || magic_number == constants::PGM_MAGIC_NUMBER || magic_number == constants::PPM_MAGIC_NUMBER;
}

std::string helpers::get_file_name_without_extension(const std::string& file_name) {
    size_t last_dot_index = file_name.find_last_of('.');
    if (last_dot_index == std::string::npos) {
        return "";
    }
    return file_name.substr(0, last_dot_index);
}

const std::vector<std::string> helpers::tokenize_line_to_strings(const std::string& line, char delimiter) {

    std::vector<std::string> tokens;
    std::string current_token;
    for (size_t i = 0; i < line.size(); i++) {

        if (line[i] == delimiter) {

            if (!current_token.empty()) {
                tokens.push_back(current_token);
                current_token.clear();
            }
        }
        else {
            current_token += line[i];
        }
    }

    if (!current_token.empty()) {
        tokens.push_back(current_token);
    }
    return tokens;
}

bool helpers::is_valid_rotation_direction(const std::string& direction) {

    return direction == constants::ROTATE_LEFT_DIRECTION || direction == constants::ROTATE_RIGHT_DIRECTION;
}