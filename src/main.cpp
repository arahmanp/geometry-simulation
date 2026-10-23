#include <cstddef>
#include <iostream>
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
    Matrix(size_t n, size_t m, double init = 0.0) : nRow(n), nCol(m), matrix(nRow, Vec(nCol, init)) {}

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
};

int main() {
    Matrix A(2, 3, -1.3);

    auto [n, m] = A.dimension();

    A[1][1] = 5.5;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cout << A[i][j] << ' ';
        }
        std::cout << '\n';
    }
}