
#include <iostream>
#include <cmath>
#include <cstdlib>

// Function to find the root using the interval bisection method
double intv_bisec(double a, double b, double (*f)(double), double eps, int maxit = 1000) {
    double m, x0;
    int iterations = 0;

    while ((b - a) > eps && iterations < maxit) {
        m = (b + a) / 2;
        if (f(m) * f(a) > 0) {
            a = m;
        } else {
            b = m;
        }
        iterations++;
    }

    x0 = (a + b) / 2;
    std::cout << "Number of iterations: " << iterations << std::endl;

    return x0;
}

// Define the functions to find roots for
double func1(double x) {
    return sin(x);
}

double func2(double x) {
    return x * x - 2;
}

int main(int argc, char* argv[]) {
    double a, b, eps;
    int maxit = 1000;

    // Parse command line arguments
    if (argc < 3 || argc > 5) {
        std::cerr << "Usage: " << argv[0] << " a b [maxit] eps" << std::endl;
        return 1;
    }

    a = std::stod(argv[1]);
    b = std::stod(argv[2]);

    if (argc >= 4) {
        maxit = std::stoi(argv[3]);
    }

    if (argc >= 5) {
        eps = std::stod(argv[4]);
    } else {
        eps = 1e-6; // Default epsilon
    }

    // Find the roots using the interval bisection method
    double root1 = intv_bisec(a, b, func1, eps, maxit);
    double root2 = intv_bisec(a, b, func2, eps, maxit);

    std::cout << "Root of sin(x) is: " << root1 << std::endl;
    std::cout << "Root of x^2 - 2 is: " << root2 << std::endl;

    return 0;
}
