#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    char s[100];
    char c1,c2;
    int i;

    fgets(s,sizeof s, stdin);
    scanf("%c %c", &c1, &c2);

    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == c1){
            s[i] = c2;
            break;
        }
    }
    printf("%s", s);
    return 0;
}