#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::Matrix2d A;
    A << 1, 2,
         3, 4;

    Eigen::Matrix2d B;
    B << 5, 6,
         7, 8;

    Eigen::Matrix2d C = A + B;

    std::cout << "Hello, World!\n";
    std::cout << "Matrix A:\n" << A << "\n\n";
    std::cout << "Matrix B:\n" << B << "\n\n";
    std::cout << "A + B:\n" << C << std::endl;

    return 0;
}
