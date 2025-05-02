$(shell mkdir -p build)

CXX = clang++
CXXFLAGS = -std=c++11 -I/opt/homebrew/opt/raylib/include
LDFLAGS = -L/opt/homebrew/opt/raylib/lib -lraylib

SRC = $(wildcard src/*.cpp)
TARGET = build/game

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)   # Make sure this line is indented with a TAB

clean:
	rm -rf build   # Add clean command to remove build directory
