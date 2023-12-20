#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    

    int x, y, z;

    scanf("%d %d %d", &x, &y, &z);

    if(x % y == 0 && x % z == 0){
        printf("O número é divisível");
    }else{
        printf("O número não é divisível");
    }





    return 0;
}