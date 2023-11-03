# Customizable Compiler Settings
MYCXX = g++
MYCXXFLAGS = -Wall -Wextra -std=c++11

# Custom Project Structure
MYBINDIR = .
MYOBJDIR = objdir
MYSRCDIR = source
MYINCDIR = include


# Define Executable
MYEXEC = $(MYBINDIR)/output

# Source Files
MYSOURCES = $(wildcard $(MYSRCDIR)/*.cpp)

# Object Files
MYOBJS = $(MYSOURCES:$(MYSRCDIR)/%.cpp=$(MYOBJDIR)/%.o)


# Build Target
all: $(MYEXEC)

$(MYEXEC): $(MYOBJS)
	$(MYCXX) $(MYCXXFLAGS) -o $@ $^

$(MYOBJDIR)/%.o: $(MYSRCDIR)/%.cpp
	$(MYCXX) $(MYCXXFLAGS) -I $(MYINCDIR) -c $< -o $@

# Clean Target
clean:
	rm -f $(MYOBJS) $(MYEXEC)
