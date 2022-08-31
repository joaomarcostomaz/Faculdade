#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int x, contador2,contador3,contador5,contador6;

    scanf("%d", &x);

    contador2 = 0;
    contador3 = 0;
    contador5 = 0;
    contador6 = 0;


    while(x >= 1){
        if((x % 2) == 0){
            contador2++;
        }
        if((x % 3) == 0){
            contador3++;
        }
        if((x % 5) == 0){
            contador5++;
        }if((x % 2) == 0 && (x % 3) == 0 && (x % 5) == 0 ){
            contador6++;
        }

        x--;



    }
        printf("Multiplos de 2: %d\nMultiplos de 3: %d\nMultiplos de 5: %d\nMultiplos de todos %d", contador2, contador3, contador5, contador6); 




    return 0;
}