#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    void media(double vet[], int n, int *i);
    int n;
    int i = 0;
    scanf("%d", &n);
    double vet[n];
    for(int i = 0; i < n; i++){
        scanf("%lf", &vet[i]);
    }
    media(vet,n,&i);

    printf("%d\n", i);

}
void media(double vet[], int n, int *i){
    double media = 0;
    *i = vet[0];
    for(int k = 0; k < n; k++){
        media += vet[k];
    }
    media /= n;
    double diferenca = 999999;
    for(int k = 0; k < n; k++){
        double diff = fabs(vet[k] - media);

        if(diff < diferenca){
            *i = k;
            diferenca = diff;
        }
    }
    
}