CC = g++
CFLAGS = -Wall -g -std=c++11
main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main