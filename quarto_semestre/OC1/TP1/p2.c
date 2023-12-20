#include <stdio.h> 


void reajusta_salario_50(int *salario, int size, int value, int *count){
    for(int i = 0; i < size; i++){
        salario[i] = salario[i] * 1.5;
        if (salario[i] > value){
            *count += 1;
        }
    }
}

int main(){
    int salario[] = {200, 190, 340,100};
    int count = 0;
    reajusta_salario_50(salario, 4, 200, &count);
    printf("count: %d\n", count);
    for(int i = 0; i < 4; i++){
        printf("%d\n", salario[i]);
    }
}