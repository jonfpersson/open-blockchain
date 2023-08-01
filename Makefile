# Compiler and compiler flags
CXX := g++
CXXFLAGS :=  -lcrypto -lssl

# Executable name
EXECUTABLE := chain

# Default target
all: $(EXECUTABLE)

# Rule to compile the source file and generate the executable
$(EXECUTABLE): main.cpp
	$(CXX)  $< -o $@ $(CXXFLAGS)

# Clean build files
clean:
	rm -f $(EXECUTABLE)