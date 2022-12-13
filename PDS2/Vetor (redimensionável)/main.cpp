#include <iostream>
#include "vetor.h"

using std::cin;
using std::cout; 
using std::endl;
using std::string;

int main() {
  int inicio, fim;
  cin >> inicio >> fim;
  Vetor<string> v(inicio, fim);
  char opcao;
  while (cin >> opcao) {
    int indice;
    string valor;
    if (opcao == 'a') {
      cin >> indice;
      cin >> v[indice];
    } else if (opcao == 'v') {
      cin >> indice;
      cout << v[indice] << endl;
    } else if (opcao == 'r') {
      cin >> inicio >> fim;
      v.Redimensionar(inicio, fim);
    } else {
      return 0;
    }
  }
  return 0;
}