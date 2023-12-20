#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

    int day, month, year;
    int dias(int day, int month, int year);

    while(scanf("%d %d %d", &day, &month, &year) != EOF){
        printf("%d\n", dias(day,month,year));
    }
}

int dias(int day, int month, int year){
    int d = 17;
    int m = 9;
    int y = 2020;
    int mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int contador = 0;
    
    if(year != y){
        for(int k = year; k <= y; k++){
            int bissexto = 0;
            if (k % 4 == 0 && ( k % 100 != 0 || k % 400 == 0)){
                    bissexto = 1;
            }
            if(k == year){
                contador += mes[month - 1] - day;
                if(bissexto == 1 && month <= 2)
                    contador++;
                for(int i = month; i < 12; i++){
                    contador += mes[i];                
                }   
            }else if(k == y){
                for(int i = 0; i < m - 1; i++){
                    contador += mes[i];                
                }   
                if(bissexto == 1 && m > 2)
                    contador++;
                contador += d + 1;
            }else{
                if(bissexto == 1){
                contador +=366;
                }else{
                    contador += 365;
                }
            }
        }
    }else{
        if(month == m){
            contador = d - day;
        }else{
            int bissexto = 0;
            if(year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0)){
                    bissexto = 1;
            }
            contador += mes[month - 1] - day;
            for(int w = month; w < m - 1; w++){
                contador += mes[w];
            }
            if(bissexto == 1 && month <= 2 && m > 2)
                contador++;
            contador += d + 1;
        }

    }
    return contador;
}
    
    

