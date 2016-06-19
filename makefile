NAME = wadEdit
SOURCES = main.c lump.c wad.c
FLAGS = -Wall

all:
	gcc $(SOURCES) -o $(NAME) $(FLAGS)
