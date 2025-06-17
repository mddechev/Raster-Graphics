#ifndef _PPM_IMAGE_HPP_
#define _PPM_IMAGE_HPP_

#include "Image.hpp"
#include "../../utils/Matrix.hpp"
#include "../../utils/Constants.hpp"
#include "../Pixel.hpp"

class PPMImage : public Image {
public:
    explicit PPMImage(const std::string& file_name, uint16_t width = 1, uint16_t height = 1, uint16_t max_color = 1);

    void load(std::istream& in) override;
    void print(std::ostream& out = std::cout) const override;
    Image* clone() const override;
    void grayscale() override;
    void monochrome() override;
    void negative() override;
    void rotate_left() override;
    void rotate_right() override;
private:
    Matrix<Pixel> data;
};


#endif 