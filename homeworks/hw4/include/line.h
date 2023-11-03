
#ifndef UNIQUE_LINE_H
#define UNIQUE_LINE_H

#include "point.h" // Include a custom header file
#include <stdexcept> // for std::invalid_argument

class Line {
private:
    Point startPoint, endPoint; // Use unique variable names

public:
    Line(const Point& startPoint, const Point& endPoint); // Constructor with unique names

    double calculatelength() const; // Method to calculate the length of the line

    // ... other member functions with unique names if needed
};

#endif //UNIQUE_LINE_H
