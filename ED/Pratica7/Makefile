CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

MAIN_OBJ= $(OBJ)/main.o
FUNC_INC = $(INC)/functions.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run: $(EXE)
		$(EXE)

$(BIN)/main: $(MAIN_OBJ)
	$(CC) -pg -o $(BIN)/main $(MAIN_OBJ) $(LIBS)

$(OBJ)/main.o: $(FUNC_INC) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

clean:
		rm -f $(EXE) $(MAIN_OBJ)
		clear