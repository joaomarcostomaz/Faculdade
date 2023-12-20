CC=g++
CFLAGS=-std=c++11 -Wall
TARGET = vpl_execution

BUILD_DIR = ./build
SRC_DIR   = ./src
INCLUDE_DIR  = ./include


${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Funcionario.o ${BUILD_DIR}/Pessoa.o ${BUILD_DIR}/Professor.o ${BUILD_DIR}/main.o
		${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/Pessoa.o: ${INCLUDE_DIR}/Pessoa.hpp ${SRC_DIR}/entidades/Pessoa.cpp
		${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/Pessoa.cpp -o ${BUILD_DIR}/Pessoa.o

${BUILD_DIR}/Funcionario.o: ${INCLUDE_DIR}/Funcionario.hpp ${SRC_DIR}/entidades/Funcionario.cpp
		${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/Funcionario.cpp -o ${BUILD_DIR}/Funcionario.o

${BUILD_DIR}/Professor.o: ${INCLUDE_DIR}/Professor.hpp ${SRC_DIR}/entidades/Professor.cpp
		${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/Professor.cpp -o ${BUILD_DIR}/Professor.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Funcionario.hpp ${INCLUDE_DIR}/Professor.hpp ${INCLUDE_DIR}/Pessoa.hpp ${SRC_DIR}/main.cpp
		${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

		
all: ${BUILD_DIR}/${TARGET}

clean:
	rm -f ${BUILD_DIR}/*