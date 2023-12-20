#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int i;
    int x, y,z,w;

    scanf("%d", &x);
    int A[x];

    for(i = 0; i < x; i++){
        scanf("%d", &z);
        A[i] = z;
    }
    scanf("%d", &y);
    int C[y]; 
    for(i = 0; i < y; i++){
        scanf("%d", &w);
        C[i] = w;
    }
    if(x > y){
        for(i = 0; i < x; i++){
            if(A[i] == C[i]){
                printf("%d\n", A[i]);
            }
        }
    }else{
        for(i = 0; i < y; i++){
            if(A[i] == C[i]){
                printf("%d\n", A[i]);
            }
        }
    }
    
    
}