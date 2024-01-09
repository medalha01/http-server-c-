# Makefile

# Variables
CC=g++  # for C, use gcc; for C++, use g++
CFLAGS=-I. # include flags, adjust as necessary
SRC_DIR=src
SRCS=$(shell find $(SRC_DIR) -name '*.cpp')  # for C, use '*.c'; for C++, use '*.cpp'
OBJS=$(SRCS:.cpp=.o)  # for C, use '.c=.o'; for C++, use '.cpp=.o'

# Default rule
all: server.o

# Rule for building server.o from all object files
server.o: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

# Generic rule for converting any .c to .o
%.o: %.c
	$(CC) -cpp -o $@ $< $(CFLAGS)

# Clean rule
clean:
	rm -f $(SRC_DIR)/*.o $(SRC_DIR)/*/*.o server.o

.PHONY: all clean

