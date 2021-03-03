#OBJ = code.o list.o
CC=gcc
CFLAGS = -Wall -pedantic -c

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

UI: UI.c code.c list.c
	gcc $(CFLAGS) $(OBJ) UI.c code.c list.c code.h