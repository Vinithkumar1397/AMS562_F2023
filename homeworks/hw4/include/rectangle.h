// ifndef directive to prevent multiple inclusions of this header
#ifndef RECTANGLE_H
#define RECTANGLE_H

// Include the custom header file "point.h"
#include "point.h"

// Declare a class named Rectangle
class Rectangle {
protected:  // Members are now protected, not private
    Point topLeft; // Declare a protected member variable for the top-left corner
    Point bottomRight; // Declare a protected member variable for the bottom-right corner

public:
    // Constructor for the Rectangle class that takes top-left and bottom-right points as input
    Rectangle(const Point& topLeft, const Point& bottomRight);

    // Declare a virtual function to calculate the area of the rectangle (may be overridden by derived classes)
    virtual double area() const;

    // Method to calculate the perimeter of the rectangle
    double perimeter() const;

    // Method to check if a given Point object is contained within the rectangle
    bool contains(const Point& p) const;

};

// endif directive to close the preprocessor conditional started with ifndef
#endif
