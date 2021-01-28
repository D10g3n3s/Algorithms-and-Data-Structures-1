CC = gcc
SOURCES = sources/point.c sources/circle.c
INCLUDES = ./includes
BINARY = ./main
PROG = sources/main.c
FLAGS = -Wall -Werror -g -lm

all:
	@$(CC) -o $(BINARY) $(PROG) $(SOURCES) -I $(INCLUDES) $(FLAGS)

run:
	@$(BINARY)

zip:
	zip -r PointCircle.zip includes sources main makefile