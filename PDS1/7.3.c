#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc,char *argv[]){

    char str[100];
    FILE *fp;

    scanf("%s", str);

    fp = fopen(str, "rb");

    long long int matriz1[5][5];
    long long int matriz2[5][5];

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            fscanf(fp,"%lld", &matriz1[i][j]);
        }
    }
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            fscanf(fp,"%lld", &matriz2[i][j]);
        }
    }
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%lld",matriz1[i][j] + matriz2[i][j] );
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}