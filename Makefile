CXX = g++
CXXFLAGS = -g -std=c++11
toComp = $(wildcard *.cpp)
toDel = taskforge

.PHONY: all compile run clean valgrind

all: compile run
	@echo "Cleaning up..."
	@$(MAKE) clean

compile:
	@$(CXX) $(CXXFLAGS) $(toComp) -o $(toDel)

run: compile
	@./$(toDel)

clean:
	@rm -f *.o *.gcov *.gcda *.gcno *.gz *.json *.html *.css output.txt coverage.txt valgrind.txt $(toDel)

valgrind: clean compile
	@valgrind --leak-check=full ./$(toDel)