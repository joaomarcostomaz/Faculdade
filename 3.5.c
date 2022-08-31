#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int m,n, i, j;
    int nmaior;

    scanf("%d %d", &m, &n);

    int A[m][n];

    for(i = 0; i < m; i++){
        for(j = 0;j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }
    nmaior = A[0][0];

    for(i = 0; i < m; i++){
        for(j = 0;j < n; j++){
            if(A[i][j] > nmaior){
                nmaior = A[i][j];
            }
        }
    }
    printf("%d", nmaior);

    return 0;
}