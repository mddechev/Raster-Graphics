#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <cstddef>
#include <vector>
#include <iostream>

template <typename type>
class Matrix {
public:
    Matrix(size_t rows = 4, size_t cols = 4);
    Matrix(size_t rows, size_t cols, const type& value);

    std::vector<type>& operator[] (size_t index);
    const std::vector<type>& operator[] (size_t index) const;

    void print(std::ostream& out = std::cout) const;
    void read(std::istream& in);

    size_t get_rows() const { return rows; }
    size_t get_cols() const { return cols; }
    size_t get_size() const { return rows * cols; }
    const type& at(size_t row, size_t col) const;
    type& at(size_t row, size_t col);

    void set_at_pos(size_t row, size_t col, const type& value);
    void set_row(size_t row, const std::vector<type>& row_data);
    void set_col(size_t col, const std::vector<type>& col_data);

    void resize(size_t rows, size_t cols);

    void transpose();
    void mirror();
    void rotate_left();
    void rotate_right();
    // Matrix get_transposed() const;

    void fill(const type& value);

private:
    std::vector<std::vector<type> > matrix;
    size_t rows;
    size_t cols;
};

template <typename type>
Matrix<type>::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {

    matrix.reserve(rows);
    matrix.resize(rows);
    for (size_t i = 0; i < rows; i++) {
        matrix[i].reserve(cols);
        matrix[i].resize(cols);
    }
}

template <typename type>
Matrix<type>::Matrix(size_t rows, size_t cols, const type& value) : rows(rows), cols(cols) {

    matrix.reserve(rows);
    matrix.resize(rows);
    for (size_t i = 0; i < rows; i++) {
        matrix[i].reserve(cols);
        matrix[i].resize(cols, value);
    }

    // fill(value);
}

template <typename type>
void Matrix<type>::read(std::istream& in) {

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            in >> matrix[i][j];
        }
    }
}

template <typename type>
const std::vector<type>& Matrix<type>::operator[] (size_t index) const {

    return matrix[index];
}

template <typename type>
std::vector<type>& Matrix<type>::operator[] (size_t index) {

    return matrix[index];
}


template <typename type>
const type& Matrix<type>::at(size_t row, size_t col) const {

    if (row >= rows || col >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }
    return matrix[row][col];
}

template <typename type>
type& Matrix<type>::at(size_t row, size_t col) {

    if (row >= rows || col >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }
    return matrix[row][col];
}

template <typename type>
void Matrix<type>::set_at_pos(size_t row, size_t col, const type& value) {

    if (row >= rows || col >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }
    matrix[row][col] = value;
}

template <typename type>
void Matrix<type>::set_row(size_t row, const std::vector<type>& row_data) {

    if (row >= rows || row_data.size() != cols) {
        throw std::out_of_range("Matrix index out of range");
    }
    matrix[row] = row_data;
}

template <typename type>
void Matrix<type>::set_col(size_t col, const std::vector<type>& col_data) {

    if (col >= cols || col_data.size() != rows) {
        throw std::out_of_range("Matrix index out of range");
    }
    for (size_t i = 0; i < rows; i++) {
        matrix[i][col] = col_data[i];
    }
}

template <typename type>
void Matrix<type>::resize(size_t rows, size_t cols) {

    this->rows = rows;
    this->cols = cols;

    matrix.resize(rows);
    for (size_t i = 0; i < rows; i++) {
        matrix[i].resize(cols);
    }
}

template <typename type>
void Matrix<type>::transpose() {

    Matrix<type> transposed(cols, rows);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) { 
            transposed.matrix[j][i] = matrix[i][j];
        }
    }

    *this = std::move(transposed);
}

// template <typename type>
// Matrix<type> Matrix<type>::get_transposed() const {

//     Matrix<type> transposed(*this);
//     transposed.transpose();

//     return transposed;
// }

template <typename type>
void Matrix<type>::mirror() {

    Matrix<type> mirrored(rows, cols);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            mirrored.matrix[i][j] = matrix[i][cols - j - 1];
        }
    }

    *this = std::move(mirrored);
}

template <typename type>
void Matrix<type>::rotate_left() {

    this->transpose();
    this->mirror();
}

template <typename type>
void Matrix<type>::rotate_right() {

    this->mirror();
    this->transpose();
}

template <typename type>
void Matrix<type>::print(std::ostream& out) const {

    for (size_t i = 0; i < rows; i++) {

        for (size_t j = 0; j < cols; j++) {

            out << matrix[i][j] << ' ';
        }
        out << '\n';
    }
    out << std::endl;
}

template <typename type>
void Matrix<type>::fill(const type& value) {

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            matrix[i][j] = value;
        }
    }
}


#endif