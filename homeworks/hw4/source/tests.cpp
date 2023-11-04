#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "square.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

// Function to compare double values for equality
bool double_equals(double a, double b, double epsilon = 0.001) {
    return std::fabs(a - b) < epsilon;
}

bool runPointTests() {
    bool allPassed = true;

    // Test default constructor
    Point p1;
    allPassed &= double_equals(p1.getXCoordinate(), 0) && double_equals(p1.getYCoordinate(), 0);

    // Test parameterized constructor
    Point p2(5.0, 12.0); // Modified values
    allPassed &= double_equals(p2.getXCoordinate(), 5) && double_equals(p2.getYCoordinate(), 12);

    // Test distance calculations
    allPassed &= double_equals(p1.distanceFromOrigin(), 0);
    allPassed &= double_equals(p2.distanceFromOrigin(), 13); // Modified distance
    allPassed &= double_equals(p1.distanceFromPoint(p2), 13);

    if (allPassed) {
        std::cout << "Point tests passed!" << std::endl;
    } else {
        std::cerr << "Point tests failed." << std::endl;
    }

    return allPassed;
}

bool runLineTests() {
    bool allPassed = true;

    // Test line length
    Point p1(1.0, 2.0);
    Point p2(6.0, 14.0); // Modified values
    Line line(p1, p2);
    allPassed &= double_equals(line.calculatelength(), 13); // Modified length

    /*  // Test 2 with identical points
     Point p3(2.0, 2.0);
    

    Line line1(p3, p3);
    allPassed &= double_equals(line.calculatelength(), 0); // Modified length and it displayed the below mentioned exception when this is executed*/

    
    // Test line with identical points
    bool exceptionThrown = false;
    try {
        Line invalidLine(p1, p1);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    allPassed &= exceptionThrown;

    if (allPassed) {
        std::cout << "Line tests passed!" << std::endl;
    } else {
        std::cerr << "Line tests failed." << std::endl;
    }

    return allPassed;
}

bool runRectangleTests() {
    bool allPassed = true;

    // Test case 1: Normal values
    Point p1(1.0, 4.0);
    Point p2(7.0, 1.0); // Modified values
    Rectangle rect(p1, p2);

    // Test case 2: Creating a rectangle with zero area
    Point zeroAreaPoint1(1.0, 1.0);
    Point zeroAreaPoint2(1.0, 1.0);
    Rectangle zeroAreaRect(zeroAreaPoint1, zeroAreaPoint2);

    allPassed &= double_equals(zeroAreaRect.area(), 0); // Edge case

    // Test area and perimeter
    allPassed &= double_equals(rect.area(), 18); // Modified area
    allPassed &= double_equals(rect.perimeter(), 18); // Modified perimeter

    // Test point containment
    Point inside(3, 3);
    Point outside(0, 0);
    Point onEdge(1, 3);
    allPassed &= rect.contains(inside);
    allPassed &= !rect.contains(outside);
    allPassed &= !rect.contains(onEdge);

    if (allPassed) {
        std::cout << "Rectangle tests passed!" << std::endl;
    } else {
        std::cerr << "Rectangle tests failed." << std::endl;
    }

    return allPassed;
}

bool runSquareTests() {
    bool allPassed = true;

    Point topLeft(1.0, 3.0);
    double sideLength = 4.0; // Modified side length
    Square square(topLeft, sideLength);

    // Test area (overridden method)
    allPassed &= double_equals(square.area(), 16); // Modified area

    // Test point containment (inherited method)
    Point inside(2.5, 2.5); // Modified point
    allPassed &= square.contains(inside);

    // Test invalid square
    bool exceptionThrown = false;
    try {
        Square invalidSquare(topLeft, -1.0);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    allPassed &= exceptionThrown;

    if (allPassed) {
        std::cout << "Square tests passed!" << std::endl;
    } else {
        std::cerr << "Square tests failed." << std::endl;
    }

    return allPassed;
}

int main() {
    bool allTestsPassed = true;

    // Run tests and update allTestsPassed
    allTestsPassed &= runPointTests();
    allTestsPassed &= runLineTests();
    allTestsPassed &= runRectangleTests();
    allTestsPassed &= runSquareTests();

    if (allTestsPassed) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cerr << "Some tests failed." << std::endl;
    }

    return allTestsPassed ? 0 : 1;
}
