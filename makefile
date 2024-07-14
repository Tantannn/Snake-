all: main

main: main.cpp src/Board.hpp
	g++ -g main.cpp -lncurses -o main
