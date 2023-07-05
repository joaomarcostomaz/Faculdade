//
// Arquivo       : fat_recur.cpp
// Conteudo      : implementacao TP 28/03
// Autor         : João Marcos Tomáz Silva Campos 
//
#include <iostream>
#include "fat.hpp"



long long unsigned int fat(int n){
    if(n <= 1) return 1;
    //for(int i; i<= 100000000; i++) sin(i);
    return n * fat(n-1);
}
long long unsigned int fat_iterativo(int n){
    int f = 1;
    while(n > 0){
        f = f * n; 
        n = n - 1; 
    }
    return f;
}

