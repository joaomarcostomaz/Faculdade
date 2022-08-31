#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int count(char *c,char letra);
    char string[100], letra;
    int soma;
    scanf("%s", string);
    getchar();
    scanf("%c", &letra);
    soma = count(string,letra);
    printf("%d", soma);
    return 0;
}
int count(char *c,char letra){
   int soma = 0;
   if(*c == '\0'){
    return 0;
   }
    if(*c == letra){
        soma = 1 + count(c + 1, letra);
    }
    if(*c != letra){
        soma = 0 + count(c + 1, letra);
    }
    return soma;

    

    
}