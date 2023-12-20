#include <iostream>
#include <vector>

using namespace std;

// Função para calcular o número de divisores de um número
int Divisores(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

// Função para gerar números altamente compostos menores que r
void AltamenteCompostos(int r) {
    int maxDivisors = 0;
    vector<int> numbers;

    for (int i = 1; i <= r; ++i) {
        int divisors = Divisores(i);
        if (divisors > maxDivisors) {
            maxDivisors = divisors;
            numbers.push_back(i);
        }
    }

    cout << "Números Altamente Compostos Menores que " << r << ":" << endl;
    for (int num : numbers) {
        cout << num << " (Número de Divisores: " << Divisores(num) << ")" << endl;
    }
}

int main() {
    int r;
    cin >> r;
    AltamenteCompostos(r);

    return 0;
}
