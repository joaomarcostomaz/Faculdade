#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int tam;
    scanf("%d", &tam);
    int vet[tam];
    int soma(int vet[], int tam);
    for(int i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }
    printf("%d", soma(vet,tam - 1));

}
int soma(int vet[], int tam){
    if(tam == 0){
       return vet[0];
    }
    return vet[tam] + soma(vet, tam - 1);
}