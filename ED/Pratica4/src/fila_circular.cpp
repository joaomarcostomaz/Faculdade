#include "../include/fila_circular.hpp"

using namespace std;

//Implementação do construtor
Fila_circular::Fila_circular(){
    frente = 0;
    tras = 0;
    tamanho = 0;
}

//Checa se a fila está vazia
bool Fila_circular::Vazia(){
    return(tamanho == 0);
}

//Checa se a fila está cheia
bool Fila_circular::Cheia(){
    return((tras + 1) % MAX_TAM == frente);
}

//Adiciona um elemento no final da fila
void Fila_circular::Enfileira(int value){
    if(tamanho == MAX_TAM){
        return;
    }
    array[tras] = value;
    tamanho++;
    tras = (tras + 1) % MAX_TAM;
}

//Remove o primeiro elemento
void Fila_circular::Desenfileira(){
    if(Vazia()){
        return;
    }
        frente = (frente + 1) % MAX_TAM;
        tamanho--;
}

//Acessa o primeiro elemento
int Fila_circular::AcessarPrimeiro(){
    if(Vazia()){
        return -1;
    }
    return array[frente];
}

int Fila_circular::Ultimo(){
    return tras;
}

void Fila_circular::Imprimir(){
    for(int i = frente; i < frente + tamanho; i++){
        cout << array[i % MAX_TAM] << endl;
    }
}

int Fila_circular::get_tamanho(){
    return tamanho;
}