#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <numeric>

template <typename T>
class Matrix {
public:
    // Support for initializer list construction
    Matrix(std::initializer_list<std::initializer_list<T>> init) {
        // Construct the matrix using the provided initializer list
        for (auto& row : init) {
            data_.push_back(std::vector<T>(row));
        }
    }

    // Constructor for specifying the number of rows and columns
    Matrix(size_t rows, size_t cols) : data_(rows, std::vector<T>(cols, T())) {}

    // Access element at specified row and column
    T& operator()(size_t row, size_t col) {
        return data_.at(row).at(col);
    }

    // Access element at specified row and column (const version)
    const T& operator()(size_t row, size_t col) const {
        return data_.at(row).at(col);
    }

    // Get the number of rows in the matrix
    size_t getRows() const {
        return data_.size();
    }

    // Get the number of columns in the matrix
    size_t getCols() const {
        return data_.size() ? data_[0].size() : 0;
    }

    // Normalize the columns of the matrix
    void normalizeColumns() {
        for (size_t col = 0; col < getCols(); ++col) {
            // Calculate the sum of values in the current column
            T colSum = std::accumulate(data_.begin(), data_.end(), T(0),
                [col](const T& sum, const std::vector<T>& row) { return sum + row[col]; });
            // Normalize the column if the sum is non-zero
            if (colSum != 0) {
                for (size_t row = 0; row < getRows(); ++row) {
                    data_[row][col] /= colSum;
                }
            }
        }
    }

private:
    // Data structure to store the matrix
    std::vector<std::vector<T>> data_;
};

#endif // MATRIX_HPP
