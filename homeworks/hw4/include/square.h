
#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle {
public:
    Square(const Point& topLeftpoint, double LengthofSide); // Constructor
    double area() const override; // 'override' keyword is correct here
};

#endif 