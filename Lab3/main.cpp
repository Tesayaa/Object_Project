#include "Matrix.h"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Matrix m1;
    Matrix m2(3);
    Matrix m3(3, 4);
    Matrix m4(2, 3);

    std::cout << "M1 dimensions: " << m1.getRows() << " x " << m1.getCols() << "\n\n";

    std::cout << "M2: identity matrix\n";
    m2.print();

    std::cout << "\nM3: zero matrix\n";
    m3.print();

    std::cout << "\nM4: zero matrix\n";
    m4.print();

    for (int i = 0; i < m2.getRows(); ++i) {
        for (int j = 0; j < m2.getCols(); ++j) {
            m2.set(i, j, i * j);
        }
    }
    std::cout << "\nM2 after filling with i * j\n";
    m2.print();

    m3.fillRandom();
    std::cout << "\nM3 after random fill\n";
    m3.print();

    Matrix transposed = m3.transpose();
    std::cout << "\nTransposed M3\n";
    transposed.print();

    std::cout << "\nEnter 6 integers for M4:\n";
    m4.inputFromKeyboard();
    std::cout << "M4 after keyboard input\n";
    m4.print();

    std::cout << "\nSum of M3 elements: " << m3.sum() << '\n';

    try {
        Matrix bad(-1, 5);
    } catch (const std::invalid_argument& error) {
        std::cout << "Caught: " << error.what() << '\n';
    }

    try {
        m3.get(100, 100);
    } catch (const std::out_of_range& error) {
        std::cout << "Caught: " << error.what() << '\n';
    }

    return 0;
}
