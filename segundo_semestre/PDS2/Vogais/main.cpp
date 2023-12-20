#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  // Conta as ocorrências.
  char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
  int ocorrencias[5] = {0, 0, 0, 0, 0};
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < 5; j++) {
      if (s[i] == vogais[j]) {
        ocorrencias[j]++;
      }
    }
  }
  // Imprime as ocorrências.
  for (int j = 0; j < 5; j++) {
    if (ocorrencias[j] > 0) {
      cout << vogais[j] << " " << ocorrencias[j] << endl;
    }
  }
  return 0;
}