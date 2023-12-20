#include <iostream>
#include <math.h>

using namespace std;

//aplica o algoritmo do pequeno teorema de fermat
bool fermat(int n){
    int a = rand() % (n - 1) + 1;
    return (int)pow(a, n - 1) % n == 1;
}

int main(){
    int n;
    cin >> n;
    if(fermat(n)){
        cout << "Provavelmente primo" << endl;
    }else{
        cout << "Composto" << endl;
    }
    return 0;
}