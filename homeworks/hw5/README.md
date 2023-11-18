
```markdown
# Project README

This project implements a basic PageRank algorithm using C++. Below is a guide on the project structure, how to compile and execute the code, and how to interpret the output.

## Project Structure

### Files:

1. **Matrix.hpp:**
   - Declaration and definition of the templated `Matrix` class.
   - Includes member functions like `setValue`, `getValue`, and `normalizeColumns`.

2. **Vector.hpp:**
   - Declaration and definition of the templated `Vector` class.
   - Includes member functions for vector operations like `setValue` and `getValue`.

3. **PageRank.hpp:**
   - Declaration and definition of the templated `pageRank` function.
   - Takes a `Matrix` and a `Vector` as input and implements the PageRank algorithm.

4. **main.cpp:**
   - Contains the `main` function where you can test your implementations.
   - Includes necessary headers for the Matrix, Vector, and PageRank.

5. **Makefile:**
   - Defines compilation rules for your project.
   - Specifies the compiler (`g++`), compiler flags (`-std=c++11 -Wall -Wextra`), object files (`OBJS`), and the target executable (`TARGET`).
   - The `all` rule compiles the target executable.
   - The `clean` rule removes object files and the target executable.

### Compilation and Execution:

To compile the project, open your terminal and navigate to the project directory. Run the following commands:

```bash
make
```

This will compile the source files and create an executable named `output`.

To execute the program, use the following command:

```bash
./output
```

## Output Interpretation

The program contains test functions in `main.cpp` to check the correctness of the implemented classes and methods. Upon successful execution, you should see output indicating whether the tests have passed.

For example:

```bash
Matrix normalization test passed!
Rank vector initialization test passed!
PageRank test passed!
PageRank convergence test passed!
All tests passed!
```

If any of the tests fail, an error message will be displayed indicating which test did not pass.

## Cleaning Up

To clean up the compiled files, use the following command:

```bash
make clean
```

This will remove the object files and the executable.

