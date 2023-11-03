
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

class Rectangle {
protected:  // Members are now protected, not private
    Point topLeft;
    Point bottomRight;

public:
    Rectangle(const Point& topLeft, const Point& bottomRight);
    virtual double area() const; // This function is now virtual
    double perimeter() const;
    bool contains(const Point& p) const;
};

#endif 