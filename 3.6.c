#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int m,n,i, j;

    scanf("%d %d", &m, &n);

    int A[m][n];
    int B[m][n];

    for(i = 0; i < m; i++){
        for(j = 0;j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0;j < n; j++){
            B[i][j] = -1 * A[i][j];
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0;j < n; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}