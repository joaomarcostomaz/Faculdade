#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

    int num;
    void bissexto(int n);
    while(scanf("%d", &num) != EOF){
        bissexto(num);
    }

}
void bissexto(int n){
    int exist = 0;

    if(n % 4 == 0){
        if(n % 100 != 0 || n % 400 == 0){
            exist = 1;
        }
    }
    printf("%d\n", exist);
    

}