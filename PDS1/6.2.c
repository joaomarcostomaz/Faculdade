#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int num;
    void primo(int n);
    while(scanf("%d", &num) != EOF){
        primo(num);
    }

}
void primo(int n){
    int exist = 1;
    if(n < 2){
        exist = -1;
        printf("%d\n", exist);
    }else{
        exist = 1;
        int z = sqrt(n);
        for(int dn = 2; dn <= z; dn++){
                if(n % dn == 0){
                exist = 0;
                break;
            }
        }
        printf("%d\n", exist);
    }
    

}