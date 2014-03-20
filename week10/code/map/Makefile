all:
	g++ -Wall -pedantic -ggdb *.cpp

test: all
	valgrind --leak-check=full ./a.out < input
