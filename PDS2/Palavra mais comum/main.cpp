#include <iostream> 
#include <map>  // Isto é uma dica. 

using namespace std;

int main() {
  map<string, int> contador;
  // Conta o número de ocorrências.
  string palavra;
  while (cin >> palavra) {
    contador[palavra]++;
  }
  // Identifica qual é a palavra mais frequente.
  string mais_frequente = 
    contador.begin()->first;  // Começa a testar pela primeira palavra. 
  for (auto par : contador) {
    if (par.second > contador[mais_frequente]) {
      mais_frequente = par.first;
    }
  }
  cout << mais_frequente << endl;
  return 0;
}