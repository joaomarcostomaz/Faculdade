#include <iostream>
#include <math.h>

using namespace std;

//Calcula se um número é inversível e se for retorna o inverso
int inversivel(int a, int n){
    int r1 = n, r2 = a, r, t1 = 0, t2 = 1, t;
    while(r2 != 0){
        int q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    if(r1 == 1){
        return t1;
    }else{
        return -1;
    }
}

int main(){
    int a, n;
    cin >> a >> n;
    int inv = inversivel(a, n);
    if(inv == -1){
        cout << "Não é inversível" << endl;
    }else{
        cout << "Inverso: " << inv << endl;
    }
    return 0;
}