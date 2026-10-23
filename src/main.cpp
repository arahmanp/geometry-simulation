#include <cstddef>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

using Vec = std::vector<double>;

class Matrix {
private:
    size_t nRow;
    size_t nCol;
    std::vector<Vec> matrix;

public:
    // Constructors
    Matrix() : nRow(1), nCol(1), matrix(nRow, Vec(nCol, 0.0)) {}
    Matrix(size_t n, size_t m, double init = 0.0) : nRow(n), nCol(m), 
        matrix(nRow, Vec(nCol, init)) {}

    // getter
    std::pair<size_t, size_t> dimension() const {
        return {nRow, nCol};
    }
    const Vec& operator[](size_t index) const {
        return matrix[index];
    }

    // Setter
    Vec& operator[](size_t index) {
        return matrix[index];
    }

    // Operators
    Matrix operator+(const Matrix &other) const {
        if(this->dimension() != other.dimension()) {
            throw std::runtime_error("Dimension is not match!");
        }

        Matrix result(nRow, nCol);

        for(size_t i = 0; i < nRow; i++) {
            for(size_t j = 0; j < nCol; j++) {
                result[i][j] = matrix[i][j] + other[i][j];
            }
        }

        return result;
    }
    Matrix operator-(const Matrix &other) const {
        if(this->dimension() != other.dimension()) {
            throw std::runtime_error("Dimension is not match!");
        }

        Matrix result(nRow, nCol);

        for(size_t i = 0; i < nRow; i++) {
            for(size_t j = 0; j < nCol; j++) {
                result[i][j] = matrix[i][j] - other[i][j];
            }
        }

        return result;
    }
    Matrix operator*(double c) const {
        Matrix result(nRow, nCol);

        for(size_t i = 0; i < nRow; i++) {
            for(size_t j = 0; j < nCol; j++) {
                result[i][j] = matrix[i][j] * c;
            }
        }

        return result;
    }
    void operator+=(const Matrix &other) {
        if(this->dimension() != other.dimension()) {
            throw std::runtime_error("Dimension is not match!");
        }

        for(size_t i = 0; i < nRow; i++) {
            for(size_t j = 0; j < nCol; j++) {
                matrix[i][j] += other[i][j];
            }
        }
    }
    void operator-=(const Matrix &other) {
        if(this->dimension() != other.dimension()) {
            throw std::runtime_error("Dimension is not match!");
        }

        for(size_t i = 0; i < nRow; i++) {
            for(size_t j = 0; j < nCol; j++) {
                matrix[i][j] -= other[i][j];
            }
        }
    }
    void operator*=(double c) {
        for(size_t i = 0; i < nRow; i++) {
            for(size_t j = 0; j < nCol; j++) {
                matrix[i][j] *= c;
            }
        }
    }
    bool operator==(const Matrix &other) {
        if(this->dimension() != other.dimension()) return false;

        for(size_t i = 0; i < nRow; i++) {
            for(size_t j = 0; j < nCol; j++) {
                if(matrix[i][j] != other[i][j]) return false;
            }
        }

        return true;
    }
    bool operator!=(const Matrix &other) {
        if(this->dimension() != other.dimension()) return true;

        for(size_t i = 0; i < nRow; i++) {
            for(size_t j = 0; j < nCol; j++) {
                if(matrix[i][j] != other[i][j]) return true;
            }
        }

        return false;
    }
};

void printMatrix(const Matrix &m) {
    auto [r, c] = m.dimension();
    for(size_t i = 0; i < r; i++) {
        for(size_t j = 0; j < c; j++) {
            std::cout << std::fixed
                      << std::setprecision(2)
                      << std::setw(8) << m[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    Matrix A(2, 3), B(2, 3, 5.5);

    Matrix C = A + B;
    printMatrix(C);

    std::cout << '\n';

    C *= 2.3;
    printMatrix(C);

    std::cout << '\n';

    Matrix D(2, 3, -1);

    C[1][1] = 0.21;
    C += D;
    printMatrix(C);

    std::cout << '\n';

    C *= (1.0 / 3);
    printMatrix(C);

    std::cout << '\n';
    std::cout << (C != D) << '\n';
}