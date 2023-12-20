#include <iostream>
#include <random>
#include <cmath>

using namespace std;

//função que calcula o mdc entre dois inteiros
int mdc(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//função que calcula a probabilidade de dois inteiros serem coprimos dado um número de testes e valores aleatórios para a e b
double calculaprob(int num_tests) {
    int co_prime_count = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000);
    
    for (int i = 0; i < num_tests; ++i) {
        int a = dis(gen);
        int b = dis(gen);
        
        if (mdc(a, b) == 1) {
            co_prime_count++;
        }
    }
    
    double ratio = static_cast<double>(co_prime_count) / num_tests;
    return ratio;
}

// função principal para testar o algoritmo
int main() {
    int test_values[] = {10, 100, 1000, 10000, 100000};

    for (int i = 0; i < 5; ++i) {
        int num_tests = test_values[i];
        double avg_ratio = 0.0;
        
        for (int j = 0; j < 10; ++j) {
            avg_ratio += calculaprob(num_tests);
        }
        avg_ratio /= 10.0;
        
        
        std::cout << num_tests << " | " << avg_ratio << "\n";
    }
        double theoretical_value = 6.0 / (M_PI * M_PI);
        std::cout << "Valor teórico: " << theoretical_value << "\n";

    return 0;
}
