#include <iostream>
#include <Eigen/Dense>
#include <array>

int main() {
#if defined(__clang__)
    std::cout << "Using Clang/LLVM\n";
#elif defined(__GNUC__)
    std::cout << "Using GCC\n";
#else
    std::cout << "Unknown compiler\n";
#endif

// Use constexpr arrays to hold "magic numbers"
constexpr std::array<double, 4> a_vals = {1, 2, 3, 4};
constexpr std::array<double, 4> b_vals = {5, 6, 7, 8};

// Map arrays to Eigen matrices
Eigen::Matrix2d A = Eigen::Map<const Eigen::Matrix<double, 2, 2>>(a_vals.data());
Eigen::Matrix2d B = Eigen::Map<const Eigen::Matrix<double, 2, 2>>(b_vals.data());

Eigen::Matrix2d C = A + B;

std::cout << "Hello, World!\n";
std::cout << "Matrix A:\n" << A << "\n\n";
std::cout << "Matrix B:\n" << B << "\n\n";
std::cout << "A + B:\n" << C << '\n';

return 0;
}
