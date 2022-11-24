#include "dicionario.h"


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
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        if (it->chave == chave){
        return it->valor;
        }
    }
}

void Dicionario::Inserir(string chave, string valor){
    Elemento p;
    p.chave = chave;
    p.valor = valor;

    elementos_.push_back(p);
}

void Dicionario::Remover(string chave){
    for(auto it = elementos_.begin(); it != elementos_.end(); it++){
        if (it->chave == chave){
        elementos_.erase(it);
        break;
        }
    }
}

void Dicionario::Alterar(string chave, string valor){
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

