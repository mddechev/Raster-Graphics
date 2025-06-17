#ifndef _IMAGE_FACTORY_HPP_
#define _IMAGE_FACTORY_HPP_

#include "types/Image.hpp"
#include "types/PBMImage.hpp"
#include "types/PGMImage.hpp"
#include "types/PPMImage.hpp"
#include "../utils/Constants.hpp"
#include "../utils/Helpers.hpp"
#include <fstream>

class ImageFactory {
public:
    static Image* create_image(const std::string& file_name);

    static void write_image(Image* image, const std::string& file_destination);

private:
    static Image* create_pbm(const std::string& file_name);
    static Image* create_pgm(const std::string& file_name);
    static Image* create_ppm(const std::string& file_name);

    static void write_pbm(Image* image, const std::string& file_destination);
    static void write_pgm(Image* image, const std::string& file_destination);
    static void write_ppm(Image* image, const std::string& file_destination);
};


#endif