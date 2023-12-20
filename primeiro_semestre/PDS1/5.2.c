#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct adress{
    char street[50];
    unsigned int number;
    char state[50];
};

typedef struct cadastro{
    char nome[50];
    unsigned int idade;
    float salario;
    struct adress endereco;
}cad;



int main(){
    cad pessoa[5];
    int i = 0,idade, num;
    char op[12], nome[25], rua[50], estado[50];
    float salario;

    while(1){
        scanf("%s", op);

        if(!strcmp(op,"inserir")){
            scanf("%s %d %f %s %d %s", nome, &idade, &salario, rua, &num, estado);

            if(i == 5){
                printf("Espaco insuficiente.\n");
                continue;
            }
            for(int j = 0;nome[j] != '\0';j++){
                pessoa[i].nome[j] = nome[j];
            }
            for(int j = 0;rua[j] != '\0';j++){
                pessoa[i].endereco.street[j] = rua[j];
            }
            for(int j = 0;estado[j] != '\0';j++){
                pessoa[i].endereco.state[j] = estado[j];
            }
            
            pessoa[i].nome[strlen(nome)] = '\0';
            pessoa[i].endereco.street[strlen(rua)]='\0';
            pessoa[i].endereco.state[strlen(estado)] = '\0';
            pessoa[i].idade = idade;
            pessoa[i].salario = salario;
            pessoa[i].endereco.number = num;

            printf("Registro %s %d %.2f %s %d %s inserido \n",pessoa[i].nome, pessoa[i].idade, pessoa[i].salario, pessoa[i].endereco.street,pessoa[i].endereco.number, pessoa[i].endereco.state);

            i++;
        }else if(!strcmp(op,"mostrar")){
            scanf("%s", nome);
            int real = 0;

        
            for(int l = 0; l < i;l++){
                if(!strcmp(pessoa[l].nome,nome)){
                    printf("Registro %s %d %.2f %s %d %s \n", pessoa[l].nome,pessoa[l].idade,pessoa[l].salario, pessoa[l].endereco.street,pessoa[l].endereco.number,pessoa[l].endereco.state);
                    real = 1;
                    break;
                }
            }
            if(!real){
                printf("Registro ausente\n");
            }
        }else{
            scanf("%s %d %f %s %d %s", nome, &idade, &salario, rua, &num, estado);
            int real = 0;
            for(int l = 0; l < i; l++){
                if(!strcmp(pessoa[l].nome,nome)){
                    pessoa[l].idade = idade;
                    pessoa[l].salario = salario;
                    for(int j = 0;rua[j] != '\0';j++)
                        pessoa[l].endereco.street[j] = rua[j];
                    pessoa[l].endereco.number = num;
                    for(int j = 0;estado[j] != '\0';j++)
                        pessoa[l].endereco.state[j] = estado[j];
                    pessoa[i].nome[strlen(nome)] = '\0';
                    pessoa[i].endereco.street[strlen(rua)]='\0';
                    pessoa[i].endereco.state[strlen(estado)] = '\0';
                    printf("Registro %s %d %.2f %s %d %s alterado \n", pessoa[l].nome,pessoa[l].idade,pessoa[l].salario, pessoa[l].endereco.street,pessoa[l].endereco.number,pessoa[l].endereco.state);
                    real = 1;
                    break;
                }
            }
            if(!real){
                printf("Registro ausente para alteracao");
            }
        }
    }
    return 0;





}