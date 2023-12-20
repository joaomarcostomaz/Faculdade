#include <iostream>
#include "fib.hpp"

using namespace std;

int Fib_iterativo(int n){
    int fn1 = 1, fn2 = 1; 
    int fn, i;

    if(n < 3) return 1;

    for(i = 3; i <= n; i++){
        fn = fn2 + fn1;
        fn2 = fn1;
        fn1 = fn;
    }
    return fn;
}
int Fibo(int n ){
    if(n < 3) return 1;
    //for(int i; i<= 100000000; i++) sin(i);
        return Fibo(n-1) + Fibo(n-2);
}