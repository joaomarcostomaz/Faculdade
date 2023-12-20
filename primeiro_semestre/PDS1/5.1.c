#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct cadastro{
    char nome[50];
    unsigned int idade;
    float salario;
}cad;



int main(){

    cad pessoa[4];
    int i = 0,idade;
    char op[12], nome[25];
    float salario;

    while(1){
        scanf("%s", op);

        if(!strcmp(op,"inserir")){
            scanf("%s %d %f", nome, &idade, &salario);

            if(i == 4){
                printf("Espaco insuficiente.\n");
                continue;
            }
            for(int j = 0;nome[j] != '\0';j++)
                pessoa[i].nome[j] = nome[j];
            
            pessoa[i].nome[strlen(nome)] = '\0';
            pessoa[i].idade = idade;
            pessoa[i].salario = salario;

            printf("Registro %s %d %.2f inserido \n",pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);

            i++;
        }else{
            scanf("%s", nome);
            int real = 0;

            for(int l = 0; l < i;l++){
                if(!strcmp(pessoa[l].nome,nome)){
                    printf("Registro %s %d %.2f \n", pessoa[l].nome,pessoa[l].idade,pessoa[l].salario);
                    real = 1;
                    break;
                }
            }
            if(!real){
                printf("Registro ausente\n");
            }
        }
    }
    return 0;





}