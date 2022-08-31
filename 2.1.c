#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    int N, X0, X1, XN, i=2;

    scanf("%d %d %d", &N, &X0, &X1);

    printf("X0: %d\nX1: %d\n", X0, X1);



    while(i <= N){
        XN = 4*X1 - 2 * X0;
        printf("X%d: %d\n", i, XN);
        X0 = X1;
        X1 = XN;
        i++;
    }


        






    return 0;
}
