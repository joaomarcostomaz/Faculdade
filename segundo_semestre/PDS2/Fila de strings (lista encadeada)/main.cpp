#include <iostream>
#include <string>

#include "fila.h"

using namespace std;

// Executa operações sobre a fila de acordo com o que é lido do teclado.
int main () {
  Fila f;
  string operacao, valor;
  while (cin >> operacao) {
    if (operacao == "p") {
      cout << f.primeiro() << endl;
    } else if (operacao == "u") {
      cout << f.ultimo() << endl;
    } else if (operacao == "t") {
      cout << f.tamanho() << endl;
    } else if (operacao == "v") {
      if (f.vazia()) {
        cout << "sim" << endl;
      } else {
        cout << "não" << endl;
      }
    } else if (operacao == "i") {
      cin >> valor;
      f.Inserir(valor);
    } else if (operacao == "r") {
      f.Remover();
    } else {
      return 0;
    }
  }
  return 0;
}