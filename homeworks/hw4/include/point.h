// ifndef directive to prevent multiple inclusions of this header
#ifndef POINT_H
#define POINT_H

// Declare a class named Point
class Point {
private:
    double x, y; // Declare private member variables for the Point class

public:
    // Constructor for Point class with default parameters
    Point(double x = 0.0, double y = 0.0);

    // Getter method to retrieve the x-coordinate
    double getXCoordinate() const;

    // Getter method to retrieve the y-coordinate
    double getYCoordinate() const;

    // Method to calculate the distance from the origin (0,0)
    double distanceFromOrigin() const;

    // Method to calculate the distance from another Point object
    double distanceFromPoint(const Point& other) const;

    // ... other member functions if needed

};

#endif //POINT_H
