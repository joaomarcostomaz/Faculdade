#include <iostream>
#include "fila.h"

using namespace std;

Fila::Fila(){
    primeiro_ = nullptr;
    ultimo_ = nullptr;
}
string Fila::primeiro(){
    return primeiro_->chave;
}

string Fila::ultimo(){
    return ultimo_->chave;
}

Fila::~Fila(){
    No* aux1 = nullptr;
    No* aux2 = primeiro_;
    while(aux2 != nullptr){
        aux1 = primeiro_;
        aux2= aux2->proximo;
        delete aux1;
    }
}
bool Fila::vazia(){
    if(primeiro_ == nullptr && ultimo_ == nullptr){
        return 1;
    }else{
        return 0;
    }
}


int Fila::tamanho(){
    int n = 0;
    No* it;
    it = primeiro_;

    for(it = primeiro_; it != nullptr; it = it->proximo){
        n++;
    }
    return n;
}
void Fila::Remover(){
     if(primeiro_ == ultimo_ ){
        delete primeiro_;
        primeiro_ = nullptr;
        ultimo_ = nullptr;
     }else{
        No*aux = new No;
        aux = primeiro_->proximo;
        delete primeiro_;
        primeiro_ = aux;
     }

}
void Fila::Inserir(string k){
    No* novo = new No;
    novo->chave = k;
    novo->proximo = nullptr;
    if(primeiro_ == nullptr){
        primeiro_ = novo;
        ultimo_ = novo;
    }else{
        ultimo_->proximo = novo;
        ultimo_ = novo;
    }
}
