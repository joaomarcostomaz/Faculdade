#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int count(char *c,char letra);
    char string[100], letra;
    scanf("%s", string);
    getchar();
    scanf("%c", &letra);
    count(string, letra);
    for(int i = 0; i < strlen(string); i++){
        if(string[i] != '0'){
            printf("%c", string[i]);
        }
    }
    return 0;
}
int count(char *c,char letra){
   if(*c == '\0'){
    return;
   }
    if(*c == letra){
        *c = '0';
    }
    return count(c + 1,letra);
    

    
}