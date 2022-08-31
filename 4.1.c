#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

        char s1[100], s2[100];
        int i;

        fgets(s1, sizeof s1, stdin);
        
        
        fgets(s2,sizeof s2,stdin);
        i = strlen(s1);
        s1[i - 1] = '\0';
        strcat(s1,s2);

        printf("%s", s1);
    

   
}