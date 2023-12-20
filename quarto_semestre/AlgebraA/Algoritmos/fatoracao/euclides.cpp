#include <iostream>
#include <math.h>

using namespace std;

// Aplica o algoritmo de euclides para achar alfa e beta tal que alfa * a + beta * b = mdc(a, b)
void euclides(int a, int b, int &alfa, int &beta){
    int r1 = a, r2 = b, r, t1 = 0, t2 = 1, t;
    while(r2 != 0){
        int q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    alfa = t1;
    beta = t2;
}

int main(){
    int a, b, alfa, beta;
    cin >> a >> b;
    euclides(a, b, alfa, beta);
    cout << "Alfa: " << alfa << endl;
    cout << "Beta: " << beta << endl;
    return 0;
}
