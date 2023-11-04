// ifndef directive to prevent multiple inclusions of this header
#ifndef SQUARE_H
#define SQUARE_H

// Include the custom header file "rectangle.h"
#include "rectangle.h"

// Declare a class named Square, which is derived from the Rectangle class
class Square : public Rectangle {
public:
    // Constructor for the Square class that takes a top-left point and the length of a side as input
    Square(const Point& topLeftpoint, double LengthofSide);

    // Declare an overridden function to calculate the area of the square
    double area() const override;

};

// endif directive to close the preprocessor conditional started with ifndef
#endif
