#include <iostream>
#include "vetor.h"

using std::cin;
using std::cout; 
using std::endl;
using std::string;

int main() {
  int inicio, fim;
  cin >> inicio >> fim;
  Vetor v(inicio, fim);
  char opcao;
  while (cin >> opcao) {
    int indice;
    string valor;
    if (opcao == 'a') {
      cin >> indice;
      cin >> valor;
      v.atribuir(indice, valor);
    } else if (opcao == 'v') {
      cin >> indice;
      valor = v.valor(indice);
      cout << valor << endl;
    } else if (opcao == 'f') {
      return 0;
    } else {
      cout << "Opção inválida!" << endl;
    }
  }
  return 0;
}