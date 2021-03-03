OBJ = date.o
CC=gcc
CFLAGS = -Wall -pedantic

%.o %.c
	gcc $(CFLAGS) -c $< -o $@

blinker: UI.c code.c list.c
	gcc $(CFLAGS) $(OBJ) -o blinker UI.c code.c list.c
