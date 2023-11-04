#include "square.h"
#include <cmath> // Include the cmath library for mathematical functions
#include <stdexcept>  // Include this to use std::invalid_argument for exception handling

// Constructor definition for the Square class
Square::Square(const Point& topLeftpoint, double LengthofSide) 
    : Rectangle(topLeftpoint, Point(topLeftpoint.getXCoordinate() + LengthofSide, topLeftpoint.getYCoordinate() - LengthofSide)) {
    // Validate sideLength
    if (LengthofSide <= 0) {
        throw std::invalid_argument("Side length must be positive.");
    }
}

// Overridden area() method for the Square class
double Square::area() const {
    double bottomrightX = bottomRight.getXCoordinate();
    double topleftx = topLeft.getXCoordinate();

    double length = bottomrightX - topleftx; // Length of a side of the square, now accessible
    return length * length; // Calculate the area of the square by squaring the side length
}
