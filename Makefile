toComp = $(wildcard *.cpp)
toDel = taskforge

all: compile run
	@echo "Cleaning up..."
	@make clean

compile:
	@g++ -g -std=c++11 $(toComp) -o $(toDel)

clean:
	@rm -f *.o *.gcov *.gcda *.gcno *.gz *.json *.html *.css output.txt coverage.txt valgrind.txt $(toDel)

run:
	@./$(toDel)

valgrind:
	@make clean
	@make compile
	@valgrind --leak-check=full ./$(toDel)