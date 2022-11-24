#include "racional.h"

#include <cmath>
#include <iostream>

using namespace std;


Racional::Racional() {
  numerador_ = 0;
  denominador_ = 1;
}

Racional::Racional(int n)  {
  numerador_ = n;
  denominador_ = 1;
}

Racional::Racional(int n, int d) {
  if(d != 0){
  numerador_ = n;
  denominador_ = d;
  }
}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::simetrico() const {
  Racional p;
  p.numerador_ = -this->numerador_;
  p.denominador_ = this->denominador_;
  p.Normalizar();
  return p;
}

Racional Racional::somar(Racional k) const {
  Racional p;
  p.denominador_ = this->denominador_ * k.denominador_;
  p.numerador_ = (this->numerador_ * k.denominador_) + ((this->denominador_ * k.numerador_));
  p.Normalizar();
  return p;
}

Racional Racional::subtrair(Racional k) const {
  Racional p;
  p.denominador_ = this->denominador_ * k.denominador_;
  p.numerador_ = (this->numerador_ * k.denominador_) - ((this->denominador_ * k.numerador_));
  p.Normalizar();
  return p;
}

Racional Racional::multiplicar(Racional k) const {
  Racional p;
  p.denominador_ = this->denominador_ * k.denominador_;
  p.numerador_ = this->numerador_ * k.numerador_;
  p.Normalizar();
  return p;
}

Racional Racional::dividir(Racional k) const {
   Racional p;
  p.denominador_ = this->denominador_ * k.numerador_;
  p.numerador_ = this->numerador_ * k.denominador_;
  p.Normalizar();
  return p;
}

void Racional::Normalizar() {
  int aux, mdc = 1;
  if(numerador_ > denominador_){
    aux = numerador_;
  }else{
    aux = denominador_;
  }
  for(int i = 2; i <= aux; i++){
    if(numerador_ % i == 0 && denominador_ % i == 0){
      mdc = i;
      // cout << mdc << endl;
    }
  }
  numerador_ = numerador_/abs(mdc);
  denominador_ = denominador_/abs(mdc);
}
