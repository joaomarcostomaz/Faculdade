#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int T, op;
    double pi, x, dn;

    dn = 1.00;
    pi = 4.00;
    scanf("%lf", &x);

    op = 0;
    T = 0;

    while(!((M_PI - pi) >=0 && (M_PI - pi) <= x)){
        op++;
        dn += 2.00;

        if((op % 2) == 0){
            pi = pi + (4.00/ dn);
        }else{
            pi = pi - (4.00/ dn);
        }
        printf("%lf\n", pi);
         T++;
    }
    printf("%d", T);


    


    return 0;
}
