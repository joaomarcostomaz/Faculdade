#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int n;
    int fibo(int n);
    scanf("%d", &n);
    printf("%d", fibo(n));

}
int fibo(int n){
    if(n == 0 || n == 1){
        return n;
    }else{
        return fibo(n-1) + fibo(n-2);
    }
}