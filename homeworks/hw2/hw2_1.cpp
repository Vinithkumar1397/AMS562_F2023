// Include necessary libraries for input/output, math functions, and string conversion
#include <iostream>
#include <cmath>
#include <cstdlib>

// Define a custom function my_function(x) = sin(x)
double my_function(double x) {
    return sin(x);
}

// Define a function to approximate the derivative using finite difference (h)
double approx_derivative_h(double x, double h) {
    return (my_function(x + h) - my_function(x)) / h;
}

// Define a function to approximate the derivative using center difference (2h)
double approx_derivative_2h(double x, double h) {
    return (my_function(x + h) - my_function(x - h)) / (2 * h);
}

// Main function
int main(int argc, char* argv[]) {
    // Check if the correct number of command line arguments are provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <h>" << std::endl;
        return 1;
    }

    // Convert the input h from a command line argument to a floating-point number
    double my_h = std::atof(argv[1]);

    // Define the value of my_x (?/3) and its true derivative
    double my_x = M_PI / 3;
    double true_derivative = cos(my_x);

    // Compute the derivatives using both finite difference (h) and center difference (2h) methods
    double derivative_h = approx_derivative_h(my_x, my_h);
    double derivative_2h = approx_derivative_2h(my_x, my_h);

    // Calculate the absolute errors for both methods
    double error_h = std::abs(derivative_h - true_derivative);
    double error_2h = std::abs(derivative_2h - true_derivative);

    // Print out the values of h, the derivatives, and the absolute errors
    std::cout << "h = " << my_h << std::endl;
    std::cout << "Approx. Derivative (h): " << derivative_h << ", Absolute Error: " << error_h << std::endl;
    std::cout << "Approx. Derivative (2h): " << derivative_2h << ", Absolute Error: " << error_2h << std::endl;

    return 0;
}
