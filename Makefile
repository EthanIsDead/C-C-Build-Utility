output: main.o
	g++ -std=c++0x -Wall main.o -o output 

main.o: main.c
	g++ -c main.c
