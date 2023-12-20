#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    void soma(int vet1[],int vet2[],int sumv[],int n);

    int *vet1 = (int *) calloc(n,sizeof(int));
    int *vet2 = (int *) calloc(n,sizeof(int));
    int *sumv = (int *) calloc(n,sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &vet1[i]);
    }
    
    for(int i = 0; i < n; i++){
        scanf("%d", &vet2[i]);
    }
    soma(vet1,vet2,sumv,n);

    free(vet1);
    free(vet2);
    free(sumv);

    vet1 = NULL;
    vet1 = NULL;
    sumv = NULL;

}
void soma(int vet1[],int vet2[],int sumv[],int n){
    for(int i = 0; i < n; i++){
        sumv[i] = vet1[i] + vet2[i];
        printf("%d\n", sumv[i]);
    }
}