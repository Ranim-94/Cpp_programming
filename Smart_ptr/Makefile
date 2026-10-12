CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = output
SRC_DIR = src
SOURCES = $(wildcard *.cpp) $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard *.hpp) $(wildcard $(SRC_DIR)/*.hpp)

# Phony targets
.PHONY: build run clean

# For template code, we only need to track headers as dependencies
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

build: $(TARGET)

run: $(TARGET)
		./$(TARGET)

clean:
	rm -f $(TARGET)
