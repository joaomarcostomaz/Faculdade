#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

    int n;
    int Soma_Primos(int n);
    int Primo(int n);

    while(scanf("%d", &n)!= EOF){
        printf("%d", Soma_Primos(n));
    }
    
}
int Soma_Primos(int n){
    int soma = 0;
    int contprimos = 0;
    for(int i = 1; contprimos < n; i++){
        if(Primo(i) == 1){
            soma += i;
            contprimos++;
        }
    }
    return soma;
}

int Primo(int n){
    int exist = 1;
    if(n < 2){
        exist = -1;
       return exist;
    }else{
        exist = 1;
        int z = sqrt(n);
        for(int dn = 2; dn <= z; dn++){
                if(n % dn == 0){
                exist = 0;
                break;
            }
        }
        return exist;
    }
    

}