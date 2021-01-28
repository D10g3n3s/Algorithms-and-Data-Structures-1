CC = gcc
SOURCES = sources/sequential_list.c sources/list.c
INCLUDES = ./includes
BINARY = ./main
PROG = sources/main.c
FLAGS = -Wall -Werror -g -lm
PROG_NAME = Sequential_List

all:
	@$(CC) -o $(BINARY) $(PROG) $(SOURCES) -I $(INCLUDES) $(FLAGS)

run:
	@$(BINARY)

zip:
	zip -r $(PROG_NAME).zip includes sources main makefile