#include <stdio.h>


void count_par_impar(int *v, int size, int *count_par, int *count_impar){
    for (int i = 0; i < size; i++){
        if (v[i] % 2 == 0){
            *count_par += 1;
        }else{
            *count_impar += 1;
        }
    }
}



int main(){
    int v[10];
    int count_par = 0;
    int count_impar = 0;
    for (int i = 0; i < 10; i++){
        scanf("%d", &v[i]);
    }
    count_par_impar(v, 10, &count_par, &count_impar);
    printf("pares: %d\n", count_par);
    printf("impares: %d\n", count_impar);
    return 0;
}