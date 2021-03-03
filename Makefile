CC=gcc

blinker: UI.c code.c list.c
	gcc -o blinker UI.c code.c list.c
