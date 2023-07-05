CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

ARVEXP_OBJ = $(OBJ)/arvexp.o
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/arvexp

run: $(EXE)
	$(EXE)
	
$(BIN)/arvexp: $(ARVEXP_OBJ)
	$(CC) -o $(BIN)/arvexp $(ARVEXP_OBJ) $(LIBS)

$(OBJ)/arvexp.o: $(SRC)/arvexp.c
	$(CC) -Dm=400 -DCARGA=1000 $(CFLAGS) -o $(OBJ)/arvexp.o $(SRC)/arvexp.c

clean:
		rm -f $(EXE) $(ARVEXP_OBJ) gmon.out
		clear
