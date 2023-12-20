#ifndef Pilha_h
#define Pilha_h
#include "fila_circular.hpp"

using namespace std;


class Pilha {
    public:
    //Construtor
    Pilha();

    //Adiciona um elemento no topo da pilha
    void Empilha(int value);

    //Retira o elemento do topo da pilha
    void Desempilha();

    //Verifica se a pilha está vazia
    bool Vazia();

    //Destroi a pilha
    void Destroi();

    void get_top();

    void Imprime();



    private:
    Fila_circular fila;
};

#endif