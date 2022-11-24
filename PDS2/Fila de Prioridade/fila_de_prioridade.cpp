#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>
#include <set>


using namespace std;

void FilaDePrioridade::Adicionar(Pessoa p) {
  if(lista_.empty()){
      lista_.push_back(p);
  }else{
      list<Pessoa>::iterator it;
      for(it = lista_.begin(); it != lista_.end(); it++){
          if(it->prioridade < p.prioridade){
              lista_.insert(it,p);
              return;
          }
      }
      lista_.push_back(p);
  }
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
  string nome;
  nome = lista_.front().nome;
  
  lista_.pop_front();

  return nome;
}

void FilaDePrioridade::Remover(string nome) {
  list<Pessoa>::iterator it = lista_.begin();
  for(it; it != lista_.end(); it++){
    if(it->nome == nome){
      lista_.erase(it);
      break;
    }
  }
}

int FilaDePrioridade::tamanho() {
  return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
  list<Pessoa>::iterator it = lista_.begin();
  vector<string> v;
  
  for(it; it != lista_.end(); it++){
      v.push_back(it->nome);
  }
 

  return v; 

}