#include "rectangle.h"
#include <cmath> // Include the cmath library for mathematical functions

// Constructor for the Rectangle class
Rectangle::Rectangle(const Point& topLeft, const Point& bottomRight) 
    : topLeft(topLeft), bottomRight(bottomRight) {}

// Method to calculate the area of the rectangle
double Rectangle::area() const {
    double length = bottomRight.getXCoordinate() - topLeft.getXCoordinate();
    double width = topLeft.getYCoordinate() - bottomRight.getYCoordinate();
    return std::abs(length * width);
    // Area = length x width
}

// Method to calculate the perimeter of the rectangle
double Rectangle::perimeter() const {
    double length = bottomRight.getXCoordinate() - topLeft.getXCoordinate();
    double width = topLeft.getYCoordinate() - bottomRight.getYCoordinate();
    return 2 * (std::abs(length) + std::abs(width));
     // Perimeter = 2 x (length + width)
}

// Method to check if a given Point p is contained within the rectangle
bool Rectangle::contains(const Point& p) const {
    double x = p.getXCoordinate();
    double y = p.getYCoordinate();
    double topleftx = topLeft.getXCoordinate();
    double toplefty = topLeft.getYCoordinate();
    double bottomRightx = bottomRight.getXCoordinate();
    double bottomRighty = bottomRight.getYCoordinate();

    return x > topleftx && x < bottomRightx &&
           y < toplefty && y > bottomRighty;
}

// ... other member function implementations
