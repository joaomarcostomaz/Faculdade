#include <iostream>
#include <cmath>
#include <utility>  // Inclui std::pair.

#include "complexo.h"

using namespace std;

pair<Complexo, Complexo> ComputarRaizes(double a, double b, double c) {
  pair<Complexo, Complexo> raizes;
  double delta = b * b - 4 * a * c;
  if (delta >= 0) {
    raizes.first = {(-b + sqrt(delta)) / (2 * a), 0.0};
    raizes.second = {(-b - sqrt(delta)) / (2 * a), 0.0};
  } else {
    raizes.first = {(-b) / (2 * a), sqrt(-delta) / (2 * a)};
    raizes.second = raizes.first.conjugado();
  }
  return raizes;
}

int main () {
  cout << "Digite os coeficientes da equação f(x) = ax^2 + bx + c:" << endl;
  double a, b, c;
  cin >> a >> b >> c;
  auto r = ComputarRaizes(a, b, c);
  cout << "(" << r.first.real() << ", " << r.first.imag() << ")" << " "
       << "(" << r.second.real() << ", " << r.second.imag() << ")" << endl;
  return 0;
}