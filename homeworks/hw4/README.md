#Homework 4

## Project Structure

The project is organized with the following directory structure:

- `include/`: This directory contains header files.
- `source/`: This directory includes the C++ source files.
- `objdir/`: This is the object file directory, where intermediate compilation files are stored.
- `output`: The executable program is generated in this directory.
- `MakeFile`:The Makefile is used with the `make` command, which automatically reads the Makefile and compiles the source code into an executable(output)

## Prerequisites

Before running the code, make sure you have the following installed:

- g++ (GNU C++ compiler)
- Linux/Unix terminal or equivalent (if not using an IDE)

## How to Compile and Execute

To compile and execute the code, follow these steps:

1. Open your terminal or command prompt.

2. Navigate to the project directory containing the `Makefile`:

   ```sh
   cd AMS562_F2023/homeworks/hw4
   ```

3. Run the `make` command to build the project:

   ```sh
   make
   ```

   This will compile the source files and generate an executable file called `output`.

4. To run the program, use the following command:

   ```sh
   ./output
   ```

   You will see the output displayed in the terminal.

## Output

The program will produce the output on the terminal when executed. It should display the results of the tests performed in the code.

## Clean Up

To clean up the project (remove object files and the executable), you can use the following command:

```sh
make clean
```
