#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x, y;

public:
    Point(double x = 0.0, double y = 0.0); // Constructor with default parameters

    double getXCoordinate() const; // Getter for x
    double getYCoordinate() const; // Getter for y

    double distanceFromOrigin() const; // Distance from the origin (0,0)
    double distanceFromPoint(const Point& other) const; // Distance from another point

    // ... other member functions if needed
};

#endif //POINT_H
