# Homework 3

## Part 1

This code demonstrates how to approximate the derivative of a function *sin(x)* at a specific point using finite difference and center difference methods, and then compares the results with the true derivative value 
We are passing a command line parameter h that is the delta in x like `./hw2_1 1e-16`.

The initial check verifies if the value of 'h' has been provided as a command line argument.
The subsequent check ensures that the provided 'h' is of type float.
Once 'h' is obtained, we proceed to compute the derivative using both finite difference and center difference techniques.
We then calculate the absolute difference between these approximations and the actual derivative (cos(x)).
This process is repeated for various values of 'h'

| Error Values for | Derivative | Center Difference|
| -----------------| ---------- | -----------------|
| **h = 1e-1** | 0.0440981 | 0.000832917 |
| **h = 1e-2** | 0.0000433842 | 8.33329e-06 |
| **h = 1e-3** | 0.000433096 | 8.3334e-08 |
| **h = 1e-4** | 4.33021e-05 | 8.33278e-10 |
| **h = 1e-16** | 0.5 | 0.5 |
   
In theory, as h decreases, the error values should decrease as well. This trend is observed up to approximately h = 1e-8. However, beyond this point, an unexpected increase in error occurs. This behavior suggests a potential numerical overflow issue, likely stemming from the fact that h is in the denominator, leading to abnormally large error values.

## Part 2
The provided code is designed to analyze a collection of N randomly generated points on a unit sphere.
It focuses on finding the maximum and minimum arc lengths between the first point and any other point.

The program takes an integer N as a command line parameter. Example input: '`./hw2_2 1e-12`'.

In the code, the initial check ensures that N has been provided as input.
The subsequent check verifies if N is greater than or equal to 2, as an arc requires at least 2 points.

Next, dynamic arrays for x, y, and z coordinates of size N are initialized to store the points.

The code proceeds to calculate the arc lengths between the first point and every other point.
The indices for maximum and minimum lengths are stored.

Finally, the program displays the results in the following format:
"Maximum arc length is `maxlength` and coordinates are `coordinates`."
"Minimum arc length is `minlength` and coordinates are `coordinates`."