#include "dicionario.h"

using namespace std;

Dicionario::Dicionario(){
    elementos_ = {};
}

int Dicionario::tamanho(){
    return elementos_.size();
}

bool Dicionario::pertence(string chave){
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        if (it->chave == chave){
        return true;
        }
    }
    return false;
}

string Dicionario::menor(){
    if(tamanho() == 0){
        DicionarioVazio error;
        throw error;
    }
    auto it = elementos_.begin();
    string menor = it->chave;
    for(it++; it != elementos_.end(); it++){
        if(it->chave < menor){
            menor = it->chave;
        }
    }
    return menor;
}

string Dicionario::valor(string chave){
    if(!pertence(chave)){
        ChaveInexistente error;
        error.chave = chave;
        throw error;
    }
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        if (it->chave == chave){
        return it->valor;
        }
    }
}

void Dicionario::Inserir(string chave, string valor){
    if(pertence(chave)){
        ChaveRepetida error;
        error.chave = chave;
        throw error;
    }
    Elemento p;
    p.chave = chave;
    p.valor = valor;

    elementos_.push_back(p);
}

void Dicionario::Remover(string chave){
    if(!pertence(chave)){
        ChaveInexistente error;
        error.chave = chave;
        throw error;
    }
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        if (it->chave == chave){
        elementos_.erase(it);
        break;
        }
    }
}

void Dicionario::Alterar(string chave, string valor){
    if(!pertence(chave)){
        ChaveInexistente error;
        error.chave = chave;
        throw error;
    }
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        if (it->chave == chave){
        it->valor = valor;
        }
    }
}

Dicionario::~Dicionario(){
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        elementos_.erase(it++);
    }
}

