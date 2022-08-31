#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int A[10], B[10], i, j = 0;

    for(i = 0; i < 10; i++){
        scanf("%d", &A[i]);
    }
    for(i = 9; i >= 0; i--){
            B[j] = A[i];
            j++;
        if(j >=10){
            break;
        }
    }

    for(i = 0; i < 10; i++){
        printf("%d\n", B[i]);
    }

}