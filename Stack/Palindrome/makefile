CC = gcc
SOURCES = sources/item.c sources/pilha.c
INCLUDES = ./includes
BINARY = ./main
PROG = sources/main.c
FLAGS = -Wall -Werror -g -lm

all:
	@$(CC) -o $(BINARY) $(PROG) $(SOURCES) -I $(INCLUDES) $(FLAGS)

run:
	@$(BINARY)

valgrind:
	@valgrind --leak-check=full $(BINARY)

zip:
	zip -r Palindrome.zip includes sources main makefile