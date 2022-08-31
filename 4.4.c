#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    char s1[100], s2[100];
    char *yes;
    
    setbuf(stdin, NULL);

    fgets(s1, 100, stdin);
    s1[strlen(s1) - 1] = '\0';

    fgets(s2, 100, stdin);
    s2[strlen(s2) - 1] = '\0';

    yes = strstr(s1,s2);
    if(yes){
        printf("É substring");
    }else{
        printf("Não é substring");
    }

}