#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

int x;

x = 233;

do{
    printf("%d\n", x);
    
    if(x < 300 || x > 400){
    x += 5;
        
}else{
    x += 3;
}

}while(x <= 457);




    return 0;
}