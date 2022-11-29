#include <string>

#include "Estoque.hpp"


void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO
  if(locker.find(mercadoria)!= locker.end()){
    locker[mercadoria] = locker[mercadoria] + qtd;
  }else{
    locker.insert({mercadoria,qtd});
  }
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO
  if(locker.find(mercadoria)!= locker.end()){
    if(locker[mercadoria] < qtd){
      cout << mercadoria << " insuficiente" << endl;
    }
      locker[mercadoria] = locker[mercadoria] - qtd;
  }else{
    cout << mercadoria << " inexistente" << endl;
  }
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  // TODO
  if(locker.find(mercadoria)!= locker.end()){
    auto it = locker.find(mercadoria);
    return it->second;
  }
}

void Estoque::imprime_estoque() const {
  // TODO
  for(auto it = locker.begin(); it != locker.end(); it++){
    cout << it->first <<", " << it->second << endl;
  }
}

map<string,unsigned int> Estoque::get_locker() const{
  return locker;
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  // TODO
  map<string,unsigned int> second_locker = rhs.get_locker();

  for(auto it = second_locker.begin(); it != second_locker.end(); it++){

    this->add_mercadoria(it->first,it->second);
  }


  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  // TODO

  map<string,unsigned int> second_locker = rhs.get_locker();

  for(auto it = second_locker.begin(); it != second_locker.end(); it++){

    this->sub_mercadoria(it->first,it->second);
  }


  return *this;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  // TODO
  map<string,unsigned int> first_locker = lhs.get_locker();
  map<string,unsigned int> second_locker = rhs.get_locker();
  

for(auto it = second_locker.begin(); it != second_locker.end(); it++){
  if(first_locker.find(it->first) != first_locker.end()){
    auto it2 = first_locker.find(it->first);
    if(it->second >= it2->second){
      return false;
    }
  }else{
    return false;
  }
  
}
    return true;
  // if (first_locker.size() < second_locker.size()){
  //   return true;
  // }else if(first_locker.size() = second_locker.size()){

  // }


  
 
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  // TODO
  map<string,unsigned int> first_locker = lhs.get_locker();
  map<string,unsigned int> second_locker = rhs.get_locker();
  

for(auto it = first_locker.begin(); it != first_locker.end(); it++){
  if(second_locker.find(it->first) != second_locker.end()){
    auto it2 = second_locker.find(it->first);
    if(it->second >= it2->second){
      return false;
    }
  }else{
    return false;
  }
  
  } 
  return true;
}