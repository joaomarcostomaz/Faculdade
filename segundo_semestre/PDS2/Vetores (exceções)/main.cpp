#include <iostream>
#include "vetor.h"

using std::cin;
using std::cout; 
using std::endl;
using std::string;

int main() {
  try {
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
  } catch (IndiceInvalido error) {
   cout << "Não foi possível executar a operação: índice " << error.indice << " não pertence ao intervalo [" << error.inicio << ", " << error.fim << "]." << endl;
  }
    catch(IndiceNaoInicializado error){
      cout << "Não foi possível executar a operação: índice " << error.indice << " não foi inicializado." << endl;
  }
    catch(IntervaloVazio error){
      cout << "Não foi possível executar a operação: intervalo [" << error.inicio << ", " << error.fim << "] é vazio." << endl;
  }
  return 0;
}