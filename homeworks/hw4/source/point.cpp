#include "point.h"
#include <cmath> // Include the cmath library for sqrt and pow functions

// Constructor for the Point class with default parameter values
Point::Point(double x, double y) : x(x), y(y) {}

// Getter method to retrieve the x-coordinate of the Point
double Point::getXCoordinate() const {
    return x;
}

// Getter method to retrieve the y-coordinate of the Point
double Point::getYCoordinate() const {
    return y;
}

// Method to calculate the distance of the Point from the origin (0,0) using the Pythagorean theorem
double Point::distanceFromOrigin() const {
    return std::sqrt(x * x + y * y);
}

// Method to calculate the distance between this Point and another Point (otherPoint)
double Point::distanceFromPoint(const Point& otherPoint) const {
    double dx = x - otherPoint.x;
    double dy = y - otherPoint.y;
    return std::sqrt(dx * dx + dy * dy);
}

// ... other member function implementations
