#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int Nlinhas, Ncolunas;
    int i, j;

    scanf("%d %d", &Nlinhas, &Ncolunas);

    int **p = (int **) malloc(Nlinhas*sizeof(int*));

    for(i = 0; i < Nlinhas; i++){
        p[i] = (int*)malloc(Ncolunas*sizeof(int));
        for(j = 0; j < Ncolunas; j++){
            scanf("%d", &p[i][j]);
            printf("%d\n", p[i][j]);
        }
    }
    free(p);
    p = NULL;
}