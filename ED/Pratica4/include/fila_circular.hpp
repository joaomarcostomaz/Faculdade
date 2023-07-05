#ifndef Fila_h
#define Fila_h

#include <iostream>

#define MAX_TAM 12


using namespace std;


class Fila_circular {
    public:
    //Método construtor.
    Fila_circular();

    //Adiciona um valor no fim da fila
    void Enfileira(int value);

    //Desinfileira o primeiro valor
    void Desenfileira();

    //Acessa o primeiro elemento
    int AcessarPrimeiro();

    //Checa se a fila está vazia
    bool Vazia();

    //Checa se a fila está cheia
    bool Cheia();

    void Imprimir();

    int Ultimo();

    int get_tamanho();


    //Destroi a fila
    void Destroi();

    private:

    int array[MAX_TAM];
    int frente, tras;
    int tamanho;
    
};

#endif