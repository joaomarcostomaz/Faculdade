#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int N;
    scanf("%d", &N);

    int *p = (int *) calloc(N,sizeof(int));

    for(int i = 0; i < N; i++){
        scanf("%d", &p[i]);
        printf("%d\n", p[i]);
    }

    free(p);
    p = NULL;

}
