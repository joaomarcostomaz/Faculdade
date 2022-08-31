#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    void print(int vet[], int n);
    void multiply(int vet[], int n, double value);

    for(int i = 0; i < n; i++){
        scanf("%d",&vetor[i]);
    }

    double value;
    scanf("%lf", &value);

    print(vetor,n);

    multiply(vetor,n,value);

    print(vetor,n);

    multiply(vetor, n, 1.0/value);

    print(vetor,n);


}
void print(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}
void multiply(int vet[], int n, double value){
    for(int i = 0; i < n; i++){
        vet[i] *= value;
    }
}