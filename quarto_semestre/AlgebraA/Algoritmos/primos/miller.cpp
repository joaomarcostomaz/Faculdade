#include <iostream>
#include <math.h>

using namespace std;

//Aplica o teste de miller 
bool miller(int n){
    int a = rand() % (n - 1) + 1;
    int s = 0;
    int d = n - 1;
    while(d % 2 == 0){
        d /= 2;
        s++;
    }
    int x = (int)pow(a, d) % n;
    if(x == 1 || x == n - 1){
        return true;
    }
    for(int i = 0; i < s - 1; i++){
        x = (x * x) % n;
        if(x == 1){
            return false;
        }
        if(x == n - 1){
            return true;
        }
    }
    return false;
}


int main(){
    int n;
    cin >> n;
    if(miller(n)){
        cout << "Provavelmente primo" << endl;
    }else{
        cout << "Composto" << endl;
    }
    return 0;
}