#include "../Utility/Matrix.hpp"
#include <cassert>
#include <stdexcept>
#include <fstream>


// void test_initialization() {

//     // Matrix<int> matrix(4, 4, 1);
//     // assert(matrix.get_cols() == 4);
//     // assert(matrix.get_cols() == 4);
//     // assert(matrix.get_size() == 16);

//     // matrix.print();
//     Matrix<int> matrix(6, 4, 1);
//     matrix.print();

//     matrix.transpose();
//     matrix.print();

//     matrix.resize(7, 7);
//     matrix.write();

//     matrix.fill_row(4, 2);
//     matrix.fill_row(5, 3);
//     matrix.fill_row(6, 4);
//     matrix.fill_col(6, 2);
//     matrix.write();
// }

// void test_copying_with_different_sizes() {
//     Matrix<int> matrix(4, 4, 1);

//     Matrix<int> matrix2(2, 2, 2);

//     std::cout << "matrix:\n";
//     matrix.print();

//     std::cout << "\nmatrix2:\n";
//     matrix2.print();

//     matrix2 = matrix;

//     std::cout << "\nmatrix2 after assignment:\n";
//     matrix2.print();
// }
// void test_copying() {

//     Matrix<int> matrix(4, 4, 1);

//     std::cout << "matrix:\n";
//     matrix.print();

//     std::cout << "\nmatrix_copy:\n";
//     Matrix<int> matrix_copy(matrix);
//     assert(matrix_copy.get_rows() == 4);
//     assert(matrix_copy.get_cols() == 4);
//     assert(matrix_copy.get_size() == 16);
//     matrix_copy.print();

//     Matrix<int> matrix_assign(4, 4, 2);
//     std::cout << "\nmatrix_assign initial:\n";
//     matrix_assign.print();

//     matrix_assign = matrix_copy;
//     std::cout << "\nmatrix_assign after assignment:\n";
//     assert(matrix_assign.get_rows() == 4);
//     assert(matrix_assign.get_cols() == 4);
//     assert(matrix_assign.get_size() == 16);

//     matrix_assign.print();
// }

// void test_transposing() {

//     Matrix<int> matrix(4, 5, 1);
//     std::cout << "matrix:\n";
//     matrix.print();

//     matrix.transpose();
//     assert(matrix.get_rows() == 5);
//     assert(matrix.get_cols() == 4);
//     assert(matrix.get_size() == 20);
//     std::cout << "matrix after transpose:\n";
//     matrix.print();

//     Matrix<int> matrix_transposed = matrix.get_transposed();
//     std::cout << "matrix_transposed:\n";
//     matrix_transposed.print();

//     assert(matrix_transposed.get_rows() == 4);
//     assert(matrix_transposed.get_cols() == 5);
//     assert(matrix_transposed.get_size() == 20);
// }

// void test_fill() {

//     Matrix<int> matrix(10, 10, 1);

//     matrix.print();

//     matrix.fill(2);

//     matrix.print();
// }

// void test_at() {

//     Matrix<int> matrix(4, 4, 1);
//     matrix.print();

//     assert(matrix.at(0, 0) == 1);
//     assert(matrix.at(0, 1) == 1);
//     assert(matrix.at(0, 2) == 1);

//     try {
//         matrix.at(4, 4);
//     } catch (const std::out_of_range& e) {
//         std::cout << "Successfully caught out of range error: " << e.what() << '\n';
//     }

// }

// void test_set_at() {

//     Matrix<int> matrix(4, 4, 1);
//     matrix.print();

//     matrix.set_at_pos(0, 0, 2);
//     assert(matrix.at(0, 0) == 2);
//     matrix.print();

//     try {
//         matrix.set_at_pos(4, 4, 2);
//     } catch (const std::out_of_range& e) {
//         std::cout << "Successfully caught out of range error: " << e.what() << '\n';
//     }
// }   

// void test_set_row() {

//     Matrix<int> matrix(4, 4, 1);
//     matrix.print();

//     std::vector<int> row;
//     row.push_back(2);
//     row.push_back(3);
//     row.push_back(4);
//     row.push_back(5);

//     matrix.set_row(0, row);
//     matrix.print();

//     try {
//         matrix.set_row(4, row);
//     } catch (const std::out_of_range& e) {
//         std::cout << "Successfully caught out of range error: " << e.what() << '\n';
//     }

//     row.push_back(6);
//     try {
//         matrix.set_row(0, row);
//     } catch (const std::out_of_range& e) {
//         std::cout << "Successfully caught out of range error: " << e.what() << '\n';
//     }
// }

// void test_set_col() {

//     Matrix<int> matrix(4, 4, 1);
//     matrix.print();

//     std::vector<int> col;
//     col.push_back(2);
//     col.push_back(3);
//     col.push_back(4);
//     col.push_back(5);

//     matrix.set_col(0, col);
//     matrix.print();

//     try {
//         matrix.set_col(4, col);
//     } catch (const std::out_of_range& e) {
//         std::cout << "Successfully caught out of range error: " << e.what() << '\n';
//     }

//     col.push_back(4);
//     try {
//         matrix.set_col(0, col);
//     } catch (const std::out_of_range& e) {
//         std::cout << "Successfully caught out of range error: " << e.what() << '\n';
//     }
// }

// void test_reading_from_file() {

//     std::ifstream file("matrix.txt");

//     Matrix<int> matrix(file, 4, 4);

//     matrix.print();
// }
// void test() {

//     Matrix<int> matrix(4, 4, 1);

//     matrix.print();

//     matrix.resize(6,6);
//     matrix.print();

//     matrix.fill(2);
//     matrix.print();
// }

void test_transpose() {
    Matrix<int> matrix(4, 4, 1);
    std::vector<int> row;
    row.push_back(2);
    row.push_back(3);
    row.push_back(4);
    row.push_back(5);
    matrix.set_row(0, row);
    std::cout << "matrix:\n";
    matrix.print();

    matrix.transpose();
    std::cout << "matrix after transpose:\n";
    matrix.print();
}

void test_mirror() {
    Matrix<int> matrix(4, 4, 1);
    std::vector<int> row;
    row.push_back(2);
    row.push_back(3);
    row.push_back(4);
    row.push_back(5);
    matrix.set_row(0, row);
    std::cout << "matrix:\n";
    matrix.print();

    matrix.mirror();
    std::cout << "matrix after mirror:\n";
    matrix.print();
}

void test_rotate_left() {

    try {
    Matrix<int> matrix(4, 4, 1);
    std::vector<int> row1;
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);
    row1.push_back(4);
    matrix.set_row(0, row1);

    std::vector<int> row2;
    row2.push_back(5);
    row2.push_back(6);
    row2.push_back(7);
    row2.push_back(8);
    matrix.set_row(1, row2);
    std::vector<int> row3;
    row3.push_back(8);
    row3.push_back(9);
    row3.push_back(10);
    row3.push_back(11);
    matrix.set_row(2, row3);
    std::vector<int> row4;
    row4.push_back(11);
    row4.push_back(12);
    row4.push_back(13);
    row4.push_back(14);
    matrix.set_row(3, row4);
    std::cout << "matrix:\n";
    matrix.print();

    matrix.rotate_right();
    std::cout << "matrix after rotate left:\n";
    matrix.print();
    } catch (const std::out_of_range& e) {
        std::cout << "Successfully caught out of range error: " << e.what() << '\n';
    }
}
int main() {
    test_rotate_left();
    return 0;
}