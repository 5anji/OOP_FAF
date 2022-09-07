CC=gcc
CFLAGS=-std=c17 -Wall -Wextra -O3 -march=native
CFLAGS_DEBUG=-std=c17 -Og
SOURCES=test.c
EXECUTABLE=a.out

build: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

debug: $(SOURCES)
	$(CC) $(CFLAGS_DEBUG) $(SOURCES) -o $(EXECUTABLE)

clean: $(EXECUTABLE)
	rm *.out
