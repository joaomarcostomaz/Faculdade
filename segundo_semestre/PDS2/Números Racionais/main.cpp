#include <iostream>

#include "racional.h"

using namespace std;

void Imprimir(Racional r) {
  cout << r.numerador() << '/' << r.denominador() << endl;
}

int main() {
  int num_a, den_a, num_b, den_b;
  cin >> num_a >> den_a >> num_b >> den_b;
  Racional a(num_a, den_a);
  Racional b(num_b, den_b);
  Imprimir(a.simetrico());
  Imprimir(b.simetrico());
  Imprimir(a.somar(b));
  Imprimir(a.subtrair(b));
  Imprimir(a.multiplicar(b));
  Imprimir(a.dividir(b));
  return 0;
}