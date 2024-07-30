# Define the compiler
CC=g++

# Compiler flags
CFLAGS=-Wall -std=c++11 -g -Iinclude

# The build target executable:
TARGET=main

# Define object files
OBJS=src/add.o src/basicblock.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

src/add.o: src/add.cpp include/add.h
	$(CC) $(CFLAGS) -c src/add.cpp -o src/add.o

src/basicblock.o: src/basicblock.cpp include/basicblock.h
	$(CC) $(CFLAGS) -c src/basicblock.cpp -o src/basicblock.o

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean
