#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    void primos(int m, int *p1, int *p2);
    int verify(int n);
    int m;
    int p1 = 0, p2 = 0;
    scanf("%d", &m);

    primos(m,&p1,&p2);
    printf("%d %d", p2, p1);
}
void primos(int m, int *p1, int *p2){
    for(int i = m - 1; i > 0; i--){
        if(verify(i) == 1){
            *p2 = i;
            break;
        }
    }
    for(int i = m + 1; i > 0; i++){
        if(verify(i) == 1){
            *p1 = i;
            break;
        }
    }
}
int verify(int n){
    if(n < 2)
        return 0;

    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return 0;
    return 1;
}