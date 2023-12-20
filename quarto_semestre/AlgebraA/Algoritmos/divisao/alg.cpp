#include <iostream>
#include <math.h>

using namespace std;

int divisao(int dividendo, int divisor){
    int quociente = 0;
    int resto = dividendo;
    while(resto >= divisor){
        resto -= divisor;
        quociente++;
    }
    return quociente;
}

//aplica o algoritmo de divisao e retorna o quociente e o resto
void divisaoComResto(int dividendo, int divisor, int &quociente, int &resto){
    quociente = 0;
    resto = dividendo;
    while(resto >= divisor){
        resto -= divisor;
        quociente++;
    }
    cout << "Quociente: " << quociente << endl;
    cout << "Resto: " << resto << endl; 
}

//Aplica o algoritmo para achar o maior divisor comum entre dois inteiros
int gcd(int a, int b){
    int resto = a % b;
    while(resto != 0){
        a = b;
        b = resto;
        resto = a % b;
    }
    return b;
}

//Aplica o algoritmo de euclides para mdc
int euclides(int a, int b){
    int resto = a % b;
    while(resto != 0){
        a = b;
        b = resto;
        resto = a % b;
    }
    return b;
}
