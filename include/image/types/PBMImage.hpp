#ifndef _PBM_IMAGE_HPP_
#define _PBM_IMAGE_HPP_

#include "Image.hpp"
#include "../../utils/Matrix.hpp"

class PBMImage : public Image {
public:
    explicit PBMImage(const std::string& file_name, uint16_t width = 1, uint16_t height = 1);

    void load(std::istream& in) override;
    void grayscale() override;
    void monochrome() override;
    void negative() override;
    void print(std::ostream& out = std::cout) const override;
    void rotate_left() override;
    void rotate_right() override;

    Image* clone() const override;

private:
    Matrix<uint16_t> data;
};



#endif