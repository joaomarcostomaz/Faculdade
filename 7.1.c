#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc,char *argv[]){

    char str[100];
    FILE *fp;

    strcpy(str,argv[1]);

    fp = fopen(str, "r");

    char reader[10000];

    int count = 0;

    while(fgets(reader, 10000, fp) != NULL){
        for(int i = 0; reader[i] != '\n'; i++){
            if(reader[i] == 'a'){
                count++;
            }
        }
    }
    printf("%d", count);
    fclose(fp);

    return 0;

}