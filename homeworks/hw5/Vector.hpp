#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>

template <typename T>
class Vector {
public:
    // Constructor with an optional initial value for all elements
    Vector(std::size_t size, T initialValue = T()) : data_(size, initialValue) {}

    // Constructor for initializer list
    Vector(std::initializer_list<T> init) : data_(init) {}

    // Get the size of the vector
    std::size_t size() const {
        return data_.size();
    }

    // Overloaded operator for accessing elements by index
    T& operator[](std::size_t index) {
        return data_.at(index);
    }

    // Overloaded operator for accessing elements by index (const version)
    const T& operator[](std::size_t index) const {
        return data_.at(index);
    }

    // Calculate the sum of all elements in the vector
    T sum() const {
        return std::accumulate(data_.begin(), data_.end(), T(0));
    }

    // Overloaded operator for scalar multiplication
    Vector<T> operator*(T scalar) const {
        Vector<T> result(size());
        for (std::size_t i = 0; i < size(); ++i) {
            result[i] = data_[i] * scalar;
        }
        return result;
    }

    // Overloaded operator for vector addition
    Vector<T> operator+(const Vector<T>& other) const {
        if (size() != other.size()) {
            throw std::invalid_argument("Vector sizes do not match for addition");
        }

        Vector<T> result(size());
        for (std::size_t i = 0; i < size(); ++i) {
            result[i] = data_[i] + other[i];
        }
        return result;
    }

    // Calculate the dot product with another vector
    T dotProduct(const Vector<T>& other) const {
        if (size() != other.size()) {
            throw std::invalid_argument("Vector sizes do not match for dot product");
        }

        T result = 0;
        for (std::size_t i = 0; i < size(); ++i) {
            result += data_[i] * other[i];
        }
        return result;
    }

    // ... (rest of the code is unchanged) ...

private:
    std::vector<T> data_;
};

#endif // VECTOR_HPP
