#include "Matrix.h"

#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>

Matrix::Matrix()
    : data_(nullptr), rows_(0), cols_(0) {
}

Matrix::Matrix(int size)
    : Matrix(size, size) {
    for (int i = 0; i < rows_; ++i) {
        data_[i][i] = 1;
    }
}

Matrix::Matrix(int rows, int cols)
    : data_(nullptr), rows_(rows), cols_(cols) {
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Matrix dimensions cannot be negative");
    }

    if (rows_ == 0 || cols_ == 0) {
        return;
    }

    data_ = new int*[rows_]{};
    try {
        for (int i = 0; i < rows_; ++i) {
            data_[i] = new int[cols_]{};
        }
    } catch (...) {
        releaseMemory();
        throw;
    }
}

Matrix::~Matrix() {
    releaseMemory();
}

int Matrix::get(int i, int j) const {
    checkIndices(i, j);
    return data_[i][j];
}

void Matrix::set(int i, int j, int value) {
    checkIndices(i, j);
    data_[i][j] = value;
}

void Matrix::inputFromKeyboard() {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            while (!(std::cin >> data_[i][j])) {
                std::cout << "Enter an integer: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
}

void Matrix::fillRandom() {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = std::rand() % 100;
        }
    }
}

void Matrix::print() const {
    if (rows_ == 0 || cols_ == 0) {
        std::cout << "(empty matrix)\n";
        return;
    }

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cout << data_[i][j] << (j + 1 == cols_ ? '\n' : ' ');
        }
    }
}

int Matrix::sum() const {
    int total = 0;
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            total += data_[i][j];
        }
    }
    return total;
}

Matrix Matrix::transpose() const {
    Matrix result(cols_, rows_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result.data_[j][i] = data_[i][j];
        }
    }
    return result;
}

int Matrix::getRows() const {
    return rows_;
}

int Matrix::getCols() const {
    return cols_;
}

void Matrix::checkIndices(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Matrix index is out of range");
    }
}

void Matrix::releaseMemory() {
    if (data_ == nullptr) {
        return;
    }

    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i];
    }
    delete[] data_;
    data_ = nullptr;
}
