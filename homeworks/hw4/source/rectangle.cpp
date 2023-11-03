#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle(const Point& topLeft, const Point& bottomRight) 
    : topLeft(topLeft), bottomRight(bottomRight) {}

double Rectangle::area() const {
    double length = bottomRight.getXCoordinate() - topLeft.getXCoordinate();
    double width = topLeft.getYCoordinate() - bottomRight.getYCoordinate();
    return std::abs(length * width);
    // Area = length x width
}

double Rectangle::perimeter() const {
    double length = bottomRight.getXCoordinate() - topLeft.getXCoordinate();
    double width = topLeft.getYCoordinate() - bottomRight.getYCoordinate();
    return 2 * (std::abs(length) + std::abs(width));
     // Perimeter = 2 x (length + width)
}

bool Rectangle::contains(const Point& p) const {
    double x = p.getXCoordinate();
    double y = p.getYCoordinate();
    double topleftx = topLeft.getXCoordinate();
    double toplefty = topLeft.getYCoordinate();
    double bottomRightx = bottomRight.getXCoordinate();
    double bottomRighty = bottomRight.getYCoordinate();

    return x > topleftx && x < bottomRightx &&
           y < toplefty && y> bottomRighty;
}

// ... other member function implementations


