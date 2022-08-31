#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int i, a;
    int vet[801];
    vet[0] = 0;
    vet[1] = 1;


    for(i = 2; i <= 800; i++){
        vet[i] = vet[i-1] + vet[i-2];
    }
    while(1){
        scanf("%d", &a);
        if(a < 0 || a > 800){
            break;
        }
        printf("%d\n", vet[i]);
    }

    return 0;
}