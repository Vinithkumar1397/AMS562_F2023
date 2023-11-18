
# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Object files
OBJS = main.o

# Executable name
TARGET = output

# Build rules

# Default rule to build the executable
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile the main source file into an object file
main_specific.o: main.cpp Matrix.hpp Vector.hpp PageRank.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

