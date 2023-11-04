#include "line.h" // Include the modified header file

// Constructor for the Line class that takes a start and end point as input
Line::Line(const Point& startPoint, const Point& endPoint)
    : startPoint(startPoint), endPoint(endPoint) {
    if (startPoint.getXCoordinate() == endPoint.getXCoordinate() && startPoint.getYCoordinate() == endPoint.getYCoordinate()) {
        throw std::invalid_argument("The start and end points cannot be the same.");
    }
}

// Method to calculate the length of the line
double Line::calculatelength() const {
    return startPoint.distanceFromPoint(endPoint); // Utilizing CustomPoint's method to calculate distance
}

// ... other member function implementations with unique names