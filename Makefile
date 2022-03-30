output: main.o
	g++ -std=c++11 -Wall -g main.o -o output 

main.o: main.c
	g++ -c main.c
