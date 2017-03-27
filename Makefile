CC = gcc
CFLAGS = -Wall
BIN = bin
SRC = src

file-static-main : $(SRC)/file-static-main.c $(SRC)/file-static-1.c $(SRC)/file-static-2.c
	$(CC) $(CFLAGS) -o $(BIN)/file-static-main $(SRC)/file-static-main.c $(SRC)/file-static-1.c $(SRC)/file-static-2.c

double-void : $(SRC)/double-void.c
	$(CC) $(CFLAGS) -o $(BIN)/double-void $(SRC)/double-void.c
