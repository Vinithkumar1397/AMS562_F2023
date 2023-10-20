# Root Finding Using Interval Bisection Method

This code is designed to find the roots of two different functions, `sin(x)` and `x^2 - 2`, using the interval bisection method. The interval bisection method is a simple yet effective numerical technique to find roots of functions within specified intervals.

## Code Explanation

The C++ code provided consists of several components:

### `intv_bisec` Function

The `intv_bisec` function is responsible for finding the root of a given function within a specified interval using the interval bisection method. The key parameters are as follows:

- `a` and `b`: Left and right endpoints of the interval.
- `f`: A pointer to the target function.
- `eps`: Comparison tolerance to stop the search when the interval becomes sufficiently small.
- `maxit` (optional): An upper bound on the number of iterations to prevent infinite loops.

Within this function, it iteratively divides the interval in half, checks the sign of the function at the midpoint, and updates the endpoints accordingly. It keeps track of the number of iterations and returns the approximate root when the interval is small enough.

### `func1` and `func2` Functions

These functions are user-defined functions representing the functions for which you want to find the roots: `sin(x)` and `x^2 - 2`, respectively. You can easily define additional functions and use them in the code.

### `main` Function

The `main` function is the entry point of the program. It handles command-line arguments to specify the interval `[a, b]`, maximum iterations, and comparison tolerance (`eps`).

- `argc` and `argv` are used to parse command-line arguments. Users provide the interval, maximum iterations (optional), and tolerance (optional) as arguments when running the program.
- It uses the `intv_bisec` function to find the roots of `func1` and `func2`.
- The code then prints the number of iterations and the calculated roots for both functions.

## Usage

To run the program, execute it in the following way:

```shell
./program_name a b [maxit] eps

