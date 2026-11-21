#include "Matrix.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Matrix a(3, 4);
    a.fillRandom();
    std::cout << "Matrix a:\n";
    a.print();

    Matrix b = a;
    b.set(0, 0, 999);
    std::cout << "\nAfter b.set(0, 0, 999):\n";
    std::cout << "Matrix a:\n";
    a.print();
    std::cout << "Matrix b:\n";
    b.print();

    Matrix c(2, 2);
    c.fillRandom();
    c = a;
    std::cout << "\nMatrix c after c = a:\n";
    c.print();

    Matrix d;
    Matrix e;
    d = e = a;
    std::cout << "\nMatrix d after d = e = a:\n";
    d.print();
    std::cout << "Matrix e after d = e = a:\n";
    e.print();

    a = a;
    std::cout << "\nMatrix a after a = a:\n";
    a.print();
    std::cout << "(should be unchanged)\n";

    Matrix empty;
    Matrix emptyCopy(empty);
    c = empty;
    std::cout << "\nEmpty matrix copied and assigned successfully: "
              << emptyCopy.getRows() << " x " << c.getCols() << '\n';

    return 0;
}
