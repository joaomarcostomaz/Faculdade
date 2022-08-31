#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int op1,op2,op3,op4,op5,op6,op7;
    float x;
    op1 = 0;
    op2 = 0;
    op3 = 0;
    op4 = 0;
    op5 = 0;
    op6 = 0;
    op7 = 0;

    scanf("%f", &x);

    while(x >= 100){
        x = x - 100;
        op1++;   
    }
    while(x >= 50){
        x = x - 50;
        op2++;
    }
    while(x >= 20){
        x = x -20;
        op3++;
    }
    while(x >= 10){
        x = x - 10;
        op4++;
    }
    while(x >= 5){
        x = x - 5;
        op5++;
    }
    while(x >= 2){
        x = x - 2;
        op6++;
    }
    while(x >= 1){
        x = x - 1;
        op7++;
    }
    printf("100: %d\n50: %d\n20: %d\n10: %d\n5: %d\n2: %d\n1: %d\n", op1, op2,op3,op4,op5,op6,op7);
    





    return 0;
}