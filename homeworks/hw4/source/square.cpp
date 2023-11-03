#include "square.h"
#include <cmath>
#include <stdexcept>  // Include this to use std::invalid_argument

// Constructor definition
Square::Square(const Point& topLeftpoint, double LengthofSide) 
    : Rectangle(topLeftpoint, Point(topLeftpoint.getXCoordinate() + LengthofSide, topLeftpoint.getYCoordinate() - LengthofSide)) {
    // Validate sideLength
    if (LengthofSide <= 0) {
        throw std::invalid_argument("Side length must be positive.");
    }
}

// Overridden area() method
double Square::area() const {
    double bottomrightX = bottomRight.getXCoordinate();
    double topleftx = topLeft.getXCoordinate();

    double length = bottomrightX - topleftx; // Now accessible
    return length * length; // No need for std::pow for squaring
}
