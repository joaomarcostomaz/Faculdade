CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

ARV_OBJ = $(OBJ)/geraarvbin.o $(OBJ)/main.o
ARV_INC = $(INC)/geraarvbin.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run: $(EXE)
		$(EXE)

$(BIN)/main: $(ARV_OBJ)
	$(CC) -pg -o $(BIN)/main $(ARV_OBJ) $(LIBS)

$(OBJ)/geraarvbin.o: $(ARV_INC) $(SRC)/geraarvbin.c
	$(CC) $(CFLAGS) -o $(OBJ)/geraarvbin.o $(SRC)/geraarvbin.c

$(OBJ)/main.o: $(ARV_INC) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

clean:
		rm -f $(EXE) $(ARV_OBJ)
		clear

