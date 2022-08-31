#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int x, soma;

    soma = 0;


    scanf("%d", &x);

    for(;x >= 1; x--){
        soma += x;
        printf("%d\n", x);
    }
    printf("%d", soma);




    return 0;

    
}