#include "line.h" // Include the modified header file

Line::Line(const Point& startPoint, const Point& endPoint)
    : startPoint(startPoint), endPoint(endPoint) {
    if (startPoint.getXCoordinate() == endPoint.getXCoordinate() && startPoint.getYCoordinate() == endPoint.getYCoordinate()) {
        throw std::invalid_argument("The start and end points cannot be the same.");
    }
}

double Line::calculatelength() const {
    return startPoint.distanceFromPoint(endPoint); // Utilizing CustomPoint's method to calculate distance
}

// ... other member function implementations with unique names

