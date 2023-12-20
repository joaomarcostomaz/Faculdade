// Código que demonstra a aplicação dos algoritmos de fatoração unica e fatoração de Fermat

#include <iostream>
#include <math.h>

using namespace std;

//Aplica o algoritmo de fatoração unica
void fatoracaoUnica(int n){
    int i = 2;
    while(n > 1){
        if(n % i == 0){
            cout << i << " ";
            n /= i;
        }else{
            i++;
        }
    }
}

//Aplica o algoritmo de fatoração de Fermat
void fatoracaoFermat(int n){
    int a = ceil(sqrt(n));
    int b2 = a*a - n;
    int b = sqrt(b2);
    while(b*b != b2){
        a++;
        b2 = a*a - n;
        b = sqrt(b2);
    }
    cout << a - b << " " << a + b << endl;
}

