#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    char s1[100], aux[100];
    int i, j;

    fgets(s1, sizeof s1, stdin);
    j = 0;
    i = strlen(s1);

    // printf("%d\n", i);
    for(i = strlen(s1) - 2; i >= 0; i--){
        aux[j] = s1[i];
        j++;
    }
    aux[j] = '\0';
    for(i = 0; i <= j-1; i++){
        s1[i] = aux[i];
    }
    printf("%s", s1);
}