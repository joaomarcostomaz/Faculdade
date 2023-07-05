CC = c++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

ConjuntoDisjunto_OBJ = $(OBJ)/ConjuntoDisjunto.o $(OBJ)/main.o
Relacao_OBJ = $(OBJ)/Relacao.o
ConjuntoDisjunto_INC = $(INC)/ConjuntoDisjunto.hpp
Relacao_INC = $(INC)/Relacao.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run:$(EXE)
	$(EXE)
	gnuplot plot.plt
	
$(BIN)/main: $(ConjuntoDisjunto_OBJ) $(Relacao_OBJ)
	$(CC) -pg -o $(BIN)/main $(ConjuntoDisjunto_OBJ) $(Relacao_OBJ) $(LIBS)

$(OBJ)/ConjuntoDisjunto.o: $(ConjuntoDisjunto_INC) $(SRC)/ConjuntoDisjunto.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ConjuntoDisjunto.o $(SRC)/ConjuntoDisjunto.cpp

$(OBJ)/Relacao.o: $(Relacao_INC) $(SRC)/Relacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Relacao.o $(SRC)/Relacao.cpp

$(OBJ)/main.o: $(ConjuntoDisjunto_INC) $(Relacao_INC) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

clean:
		rm -f $(EXE) $(ConjuntoDisjunto_OBJ) $(Relacao_OBJ) gmon.out
		clear
