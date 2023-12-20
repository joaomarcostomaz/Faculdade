CC = c++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

FAT_OBJ = $(OBJ)/fat.o $(OBJ)/fat_func.o
FAT_INC = $(INC)/fat.hpp
FIB_OBJ = $(OBJ)/Fibo.o $(OBJ)/Fibo_func.o
FIB_INC = $(INC)/fib.hpp
CFLAGS = -Wall -c -I$(INC)

EXE1 = $(BIN)/fat
EXE2 = $(BIN)/Fibo

fat: $(EXE1)
	$(EXE1)

Fibo: $(EXE2)
	$(EXE2)

$(BIN)/fat: $(FAT_OBJ)
	$(CC) -pg -o $(BIN)/fat $(FAT_OBJ) $(LIBS)

$(OBJ)/fat.o: $(FAT_INC) $(SRC)/fat.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fat.o $(SRC)/fat.cpp

$(OBJ)/fat_func.o: $(FAT_INC) $(SRC)/fat_func.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fat_func.o $(SRC)/fat_func.cpp

$(BIN)/Fibo: $(FIB_OBJ)
	$(CC) -pg -o $(BIN)/Fibo $(FIB_OBJ) $(LIBS)

$(OBJ)/Fibo.o: $(FAT_INC) $(SRC)/Fibo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Fibo.o $(SRC)/Fibo.cpp

$(OBJ)/Fibo_func.o: $(FAT_INC) $(SRC)/Fibo_func.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Fibo_func.o $(SRC)/Fibo_func.cpp

cleanfat:
    rm -f $(EXE1) $(FAT_OBJ) gmon.out

cleanFibo:
    rm -f $(EXE2) $(FIB_OBJ) gmon.out

