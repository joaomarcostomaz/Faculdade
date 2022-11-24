#include <iostream>

#include "racional.h"

using namespace std;

int main() {
  Racional a;
  Racional b;
  cin >> a >> b;
  cout << static_cast<string>(a) << endl;
  cout << static_cast<string>(b) << endl;
  cout << static_cast<float>(a) << endl;
  cout << static_cast<float>(b) << endl;
  cout << -a << endl;
  cout << -b << endl;
  cout << a + b << endl;
  cout << a - b << endl;
  cout << a * b << endl;
  cout << a / b << endl;
  return 0;
}