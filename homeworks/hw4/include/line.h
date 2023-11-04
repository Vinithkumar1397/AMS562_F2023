// ifndef directive to prevent multiple inclusions of this header
#ifndef UNIQUE_LINE_H
#define UNIQUE_LINE_H

#include "point.h" // Include a custom header file

#include <stdexcept> // Include the standard C++ library header for exceptions

// Declare a class named Line
class Line {
private:
    Point startPoint, endPoint; // Declare private member variables for Line class with unique variable names

public:
    // Constructor for Line class, taking two Point objects as arguments
    Line(const Point& startPoint, const Point& endPoint);

    // Method to calculate the length of the line
    double calculatelength() const;

    // ... other member functions with unique names if needed

};

#endif //UNIQUE_LINE_H
