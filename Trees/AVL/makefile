CC = gcc
SOURCES = sources/avl.c
INCLUDES = ./includes
BINARY = ./main
PROG = sources/main.c
FLAGS = -Wall -Werror -g -lm
PROG_NAME = AVL-Implementation
VFLAGS = --leak-check=full --track-origins=yes --show-leak-kinds=all -s

all:
	@$(CC) -o $(BINARY) $(PROG) $(SOURCES) -I $(INCLUDES) $(FLAGS)

run:
	@$(BINARY)

valgrind:
	@valgrind $(VFLAGS) $(BINARY)

zip:
	zip -r $(PROG_NAME).zip includes sources main makefile