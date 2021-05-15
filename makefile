CC = g++
CFLAGS = -Wall -g -std=c++14
main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main