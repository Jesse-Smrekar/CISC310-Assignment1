CC=g++

all: pointers.o
	$(CC) pointers.o -o pointers
pointers.o:
	$(CC) -c -std=c++11 pointers.cpp
clean:
	rm pointers pointers.o
