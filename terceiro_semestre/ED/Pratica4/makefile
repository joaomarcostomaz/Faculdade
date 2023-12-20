CC = c++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

Fila_OBJ= $(OBJ)/fila_circular.o
Pilha_OBJ = $(OBJ)/pilha.o $(OBJ)/main.o
Fila_INC= $(INC)/fila_circular.hpp
Pilha_INC = $(INC)/pilha.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run: $(EXE)
		$(EXE)

$(BIN)/main: $(Fila_OBJ) $(Pilha_OBJ)
		$(CC) -pg -o $(BIN)/main $(Fila_OBJ) $(Pilha_OBJ) $(LIBS)

$(OBJ)/fila_circular.o: $(Fila_INC) $(SRC)/fila_circular.cpp
		$(CC) $(CFLAGS) -o $(OBJ)/fila_circular.o $(SRC)/fila_circular.cpp
	
$(OBJ)/pilha.o: $(Pilha_INC) $(SRC)/pilha.cpp
		$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cpp

$(OBJ)/main.o: $(Pilha_INC) $(SRC)/main.cpp
		$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

clean:
		rm -f $(EXE) $(Pilha_OBJ) $(Fila_OBJ)
		clear