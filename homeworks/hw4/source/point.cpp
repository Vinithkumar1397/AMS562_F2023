#include "point.h"
#include <cmath> // for std::sqrt and std::pow

Point::Point(double x, double y) : x(x), y(y) {} // Constructor implementation

double Point::getXCoordinate() const { return x; } // Getter for x
double Point::getYCoordinate() const { return y; } // Getter for y

double Point::distanceFromOrigin() const {
    return std::sqrt(x * x + y * y); // Pythagorean theorem
}

double Point::distanceFromPoint(const Point& otherPoint) const {
    double dx = x - otherPoint.x;
    double dy = y - otherPoint.y;
    return std::sqrt(dx * dx + dy * dy);

}

// ... other member function implementations
