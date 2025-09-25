
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -g
SRC_DIR = src
OUT_DIR = output
SOURCES = $(wildcard *.cpp)
SRC_OBJS = $(SOURCES:%.cpp=$(OUT_DIR)/%)
HEADERS = $(wildcard *.hpp) $(wildcard $(SRC_DIR)/*.hpp)
SRC_EXTRA = $(wildcard $(SRC_DIR)/*.cpp)

.PHONY: all clean run build

all: $(SRC_OBJS)

build:
	@echo "Usage: make build <source>.cpp"

build_%: main_%.cpp $(SRC_EXTRA) $(HEADERS)
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $< $(SRC_EXTRA) -o $(OUT_DIR)/main_$*

run_%: build_%
	./$(OUT_DIR)/main_$*

clean:
	rm -rf $(OUT_DIR)
