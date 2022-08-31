#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc,char *argv[]){

    char str[100];
    FILE *fp;

    scanf("%s", str);

    fp = fopen(str, "rb");

    char reader[400000];

    int count = 0;

    fread(&reader,sizeof(char),400000,fp);

    for(int i = 0; reader[i] != '\0'; i++){
        if(reader[i] == 'a'){
            count++;
        }
    }
    printf("%d", count);
    fclose(fp);
    
    return 0;
}