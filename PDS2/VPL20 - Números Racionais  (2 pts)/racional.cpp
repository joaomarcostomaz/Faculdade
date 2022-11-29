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
  Simplificar();
  }
}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::operator-() const {
  Racional p;
  p.numerador_ = -this->numerador_;
  p.denominador_ = this->denominador_;
  p.Simplificar();
  return p;
}

Racional Racional::operator+(Racional k) const {
  Racional p;
  p.denominador_ = this->denominador_ * k.denominador_;
  p.numerador_ = (this->numerador_ * k.denominador_) + ((this->denominador_ * k.numerador_));
  p.Simplificar();
  return p;
}

Racional Racional::operator-(Racional k) const {
  Racional p;
  p.denominador_ = this->denominador_ * k.denominador_;
  p.numerador_ = (this->numerador_ * k.denominador_) - ((this->denominador_ * k.numerador_));
  p.Simplificar();
  return p;
}

Racional Racional::operator*(Racional k) const {
  Racional p;
  p.denominador_ = this->denominador_ * k.denominador_;
  p.numerador_ = this->numerador_ * k.numerador_;
  p.Simplificar();
  return p;
}

Racional Racional::operator/(Racional k) const {
   Racional p;
   if(k.denominador_ == 0){
    ExcecaoDivisaoPorZero error;
    throw error;
   }
  p.denominador_ = this->denominador_ * k.numerador_;
  p.numerador_ = this->numerador_ * k.denominador_;
  p.Simplificar();

  return p;
}

Racional::operator float() const{
    float n = numerador_;
    float d = denominador_;
    return n/d;
}

Racional::operator string() const{
    string n = to_string(numerador_);
    string d = to_string(denominador_);
    return n + '/' + d;
}

ostream& operator<<(ostream& out, Racional r){
    out << string(r);
    return out;
}
istream& operator>>(istream& in, Racional& r){
    int n;
    int d;
    in >> n;
    in >> d;
    r = Racional(n,d);
    return in;
}



void Racional::Simplificar() {
  int aux, mdc = 1;
  if(numerador_ == 0){
      denominador_ = 1;
      return;
  }
  if(abs(numerador_) > abs(denominador_)){
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


