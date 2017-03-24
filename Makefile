CC = gcc
CFLAGS = -Wall
BIN = bin
SRC = src

static-main : $(SRC)/static-main.c $(SRC)/static-1.c $(SRC)/static-2.c
	$(CC) $(CFLAGS) -o $(BIN)/static-main $(SRC)/static-main.c $(SRC)/static-1.c $(SRC)/static-2.c
