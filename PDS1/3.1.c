#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int dn, result = 0,i, A, B;
    int vet [10001];
    vet[0]= 0;
    vet[1]= 0;

    for(i = 2; i <= 10000; i++){
        result = 0;
        for(dn = 2; dn < i; dn++){

            if(i % dn == 0){
                result++;
                break;
            }
        }
        if(result == 0){
            vet[i] = 1;
        }else{
            vet[i] = 0;
        }
    }
    scanf("%d %d", &A, &B);

    if(A > 0 && A < 10000 ){
        if(B > 0 && B < 10000){
            for(i = A; i <= B; i++){
                if(vet[i] == 1){
                printf("%d\n", i);
                }
            }
        }
    }
    

    return 0;

}


   
