CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

AVL_OBJ = $(OBJ)/AVL.o $(OBJ)/main.o
AVL_INC = $(INC)/AVL.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run: $(EXE)
		$(EXE) 
	
$(BIN)/main: $(AVL_OBJ)
	$(CC) -pg -o $(BIN)/main $(AVL_OBJ) $(LIBS)

$(OBJ)/AVL.o: $(AVL_INC) $(SRC)/AVL.c
	$(CC) $(CFLAGS) -o $(OBJ)/AVL.o $(SRC)/AVL.c

$(OBJ)/main.o: $(AVL_INC) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

clean:
		rm -f $(EXE) $(AVL_OBJ)
		clear
