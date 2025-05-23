CXX = g++
CXXFLAGS = -Wall -std=c++20
TARGET = main
SRC_DIR = src
SRC = main.cpp $(wildcard $(SRC_DIR)/*.cpp)

.PHONY: all clean run rebuild valgrind

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -f $(TARGET) *.o $(SRC_DIR)/*.o

rebuild: clean all
