CXX = g++
CXXFLAGS = -Wall -std=c++20
TARGET = main.exe
SRC = ej3.cpp

.PHONY: all clean run rebuild valgrind

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -f main.exe 

rebuild: clean all
