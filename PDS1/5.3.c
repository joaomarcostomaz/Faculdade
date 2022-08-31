#include <stdio.h>
#include <string.h>

typedef struct product{
    char name[50];
    char label[50];
    float price;
}product;

int main(){

    product produto[8];
    int i=0, j = 0, k = 0;
    char marcas[8][50] = {'\0'};
    int cont[8] = {0};
    float mtotal = 0.00,mMarca[8] = {0.00};

    // ler os 8 produtos
    for(i = 0; i < 8; i++){
        scanf("%s %s %f", produto[i].name,produto[i].label,&produto[i].price);
        j = 0;
        // percorrendo as marcas para ver se a marca atual ja existe
        for(k = 0; k < i; k++){
            // se existe
            if(!strcmp(marcas[k],produto[i].label)){
                cont[k]++;
                j = 1;
                break;
            }
        }
        // se não existe
        if(!j){
            // copia a marca para dentro do vetor de strings. l é a posição da string
            for(int l = 0;produto[i].label[l] != '\0' ; l++){
                marcas[k][l] = produto[i].label[l];
            }
            cont[k]++;
        }
        // fazendo as medias
        mtotal += produto[i].price;
        mMarca[k] += produto[i].price;
    }
    for(i = 0; i < 8; i++){
        if(cont[i] != 0){
            printf("%s %d \n", marcas[i],cont[i]);
        }
    }
    printf("media total %.2f\n", mtotal/8);

    for(i = 0; i < 8; i++){
        if(cont[i] != 0){
            printf("media %s %.2f\n", marcas[i],mMarca[i]/cont[i]);
        }
    }


}