# Makefile to build C++ programs

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++20 -Werror -pedantic

# Linker flags
LDFLAGS = 

# Make all target
all: $(basename $(wildcard *.cpp))

# Rule for building targets
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@.out $(LDFLAGS)

# Rule for cleaning up
clean:
	rm -f $(basename $(wildcard *.cpp))

.PHONY: all clean

