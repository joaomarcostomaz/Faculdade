#include <iostream>
#include <cmath>
#include <utility>  // Inclui std::pair.
#include <vector>
#include <string>

#include "vetor.h"

using namespace std;

Vetor::Vetor(int inicio, int fim){
    if(fim < inicio){
        IntervaloVazio error{inicio, fim};
        throw error;
    }
    inicio_ = inicio;
    fim_ = fim;
    fim += abs(inicio);
        elementos_ = new string[fim + 1];
        inicializados_ = new bool[fim + 1];
}

void Vetor::atribuir(int i, string valor){
    int idx;
    if(i < inicio_ || i > fim_){
        IndiceInvalido error{inicio_, fim_, i};
        throw error;
    }
    if(i == inicio_){
        idx = 0;
    }else{
    idx = abs(inicio_) + i;
    }
    *(elementos_ + idx) = valor;
    *(inicializados_ + idx) = true;
}

string Vetor::valor(int i) const {
    if(i < inicio_ || i > fim_){
        IndiceInvalido error{inicio_, fim_, i};
        throw error;
    }
    int idx;
    if(i == inicio_){
        idx = 0;
    }else{
    idx = abs(inicio_) + i;
    }
    if(*(inicializados_ + idx) == false){
        IndiceNaoInicializado error{i};
        throw error;
    }
    return *(elementos_ + idx);
}

Vetor::~Vetor(){
    delete [] elementos_;
    delete [] inicializados_;
}



