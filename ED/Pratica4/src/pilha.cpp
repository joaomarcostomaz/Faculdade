#include "../include/pilha.hpp"

using namespace std;

// Metódo construtor
Pilha::Pilha(){
    Fila_circular();
    cout << "a pilha foi criada" << endl;
}

//Adiciona um elemento na pilha
void Pilha::Empilha(int value){
    fila.Enfileira(value);


    for(int i = 0; i < fila.get_tamanho() - 1; i++){
        fila.Enfileira(fila.AcessarPrimeiro());
        fila.Desenfileira();
    }
}

//Retira o elemento do topo da pilha
void Pilha:: Desempilha(){
    if(fila.Vazia()){
        cout << "pilha vazia" << endl;
        return;
    }

    fila.Desenfileira();
}

// Verifica se a pilha está vazia
bool Pilha:: Vazia(){
    return fila.Vazia();
}

void Pilha::Destroi(){
    while(!fila.Vazia()){
        get_top();
        fila.Desenfileira();
    }
    cout << "A pilha foi destruida" << endl;
}

void Pilha::Imprime(){
    if(Vazia()){
        cout << "pilha vazia";
        return;
    }
    fila.Imprimir();
}
void Pilha::get_top(){
        cout << "o valor " << fila.AcessarPrimeiro()<< " foi desempilhado" << endl;
    }


