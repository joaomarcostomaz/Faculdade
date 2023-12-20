#include <iostream>
#include <math.h>

using namespace std;

//Aplica o algoritmo chines do resto para resolver um sistema de congruências

//Algorimto de euclides
int euclides(int a, int b, int &alfa, int &beta){
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
    return r1;
}

//algoritmo chines do resto
int chinest(int a[], int m[], int n){
    int M = 1;
    for(int i = 0; i < n; i++){
        M *= m[i];
    }
    int M1[n];
    for(int i = 0; i < n; i++){
        M1[i] = M / m[i];
    }
    int y[n];
    for(int i = 0; i < n; i++){
        int alfa, beta;
        euclides(M1[i], m[i], alfa, beta);
        y[i] = alfa;
    }
    int x = 0;
    for(int i = 0; i < n; i++){
        x += a[i] * M1[i] * y[i];
    }
    return x % M;
}

int main(){
    int n;
    cin >> n;
    int a[n], m[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> m[i];
    }
    cout << chinest(a, m, n) << endl;
    return 0;
}