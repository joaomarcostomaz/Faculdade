#include <iostream>
#include <cmath>
#include <utility>  // Inclui std::pair.
#include <vector>
#include <string>

#include "vetor.h"

using namespace std;

Vetor::Vetor(int inicio, int fim){
    inicio_ = inicio;
    fim += abs(inicio);
        elementos_ = new string[fim + 1];
}

void Vetor::atribuir(int i, string valor){
    int idx;
    if(i == inicio_){
        idx = 0;
    }else{
    idx = abs(inicio_) + i;
    }
    *(elementos_ + idx) = valor;
}

string Vetor::valor(int i) const {
    int idx;
    if(i == inicio_){
        idx = 0;
    }else{
    idx = abs(inicio_) + i;
    }
    return *(elementos_ + idx);
}

Vetor::~Vetor(){
    delete [] elementos_;
}