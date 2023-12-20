
#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
  modulo_ = 0;
  argumento_ = 0;
}

Complexo::Complexo(double a, double b) {
  modulo_ = sqrt(a*a + b*b);
  argumento_ = atan(b/a);
}

double Complexo::real() {
  double real = modulo_ * cos(argumento_);
  return real;
}

double Complexo::imag() {
  double imag = modulo_ * sin(argumento_);
  return imag;
}

bool Complexo::igual(Complexo x) {
  if(modulo_ == x.modulo_ && argumento_ == x.argumento_){

  return 1.0;
  }else{
    return 0;
  }
}

void Complexo::Atribuir(Complexo x) {
  x.modulo_ = this->modulo_;
  x.argumento_ = this->argumento_;
}

double Complexo::modulo() {
  return modulo_;
}

Complexo Complexo::conjugado() {
  Complexo c;
  c.modulo_ = modulo_;
  c.argumento_ = argumento_ * -1;
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c;
  c.modulo_ = modulo_* -1;
  c.argumento_ = argumento_;
  return c;
}

Complexo Complexo::inverso() {
  Complexo i;
  i.modulo_ = 1/i.modulo_;
  i.argumento_ = argumento_;
  return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s;
  s.modulo_ += modulo_;
  s.argumento_ += argumento_;
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s;
  s.modulo_ -= modulo_;
  s.argumento_ -= argumento_;
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  p.modulo_ *= modulo_;
  p.argumento_ += argumento_;
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo d;
  d.modulo_ /= modulo_;
  d.argumento_ -= argumento_;
  return d;
}


