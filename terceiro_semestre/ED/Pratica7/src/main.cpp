#include "../include/functions.hpp"
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <iostream>
#include <sys/resource.h>
#define MAXTAM 2000000

using namespace std;


int main(){
    srand(time(0));
    struct timespec clock_f_start, clock_f_end, clock_sec_start, clock_sec_end;
    struct rusage f_start, f_end, sec_start, sec_end; 
    double T_sys_first, T_user_first, T_clock_first, T_sys_second, T_user_second, T_clock_second;
    
    int v1[MAXTAM + 1],v2[MAXTAM + 1 ],v3[MAXTAM + 1] ,v4[MAXTAM + 1],v5[MAXTAM + 1];
    int v6[MAXTAM + 1],v7[MAXTAM + 1 ],v8[MAXTAM + 1];


    for (int i = 1; i <= MAXTAM; i ++){
        v1[i] = rand() % MAXTAM;
        v2[i] = rand() % MAXTAM;
        v3[i] = rand() % MAXTAM;
        v4[i] = rand() % MAXTAM;
        v5[i] = rand() % MAXTAM;
        v6[i] = rand() % MAXTAM;
        v7[i] = rand() % MAXTAM;
        v8[i] = rand() % MAXTAM;
    }

    //Shellsort para cada vetor
    getrusage(RUSAGE_SELF, &f_start);
    clock_gettime(CLOCK_MONOTONIC, &clock_f_start);
    functions::shellsort(v1,MAXTAM);
    functions::shellsort(v2,MAXTAM);
    functions::shellsort(v3,MAXTAM);
    functions::shellsort(v4,MAXTAM);
    functions::shellsort(v5,MAXTAM);
    functions::shellsort(v6,MAXTAM);
    functions::shellsort(v7,MAXTAM);
    functions::shellsort(v8,MAXTAM);
    getrusage(RUSAGE_SELF, &f_end);
    clock_gettime(CLOCK_MONOTONIC, &clock_f_end);

    //Calculando tempos para o shellsort
    T_clock_first = (clock_f_end.tv_sec - clock_f_start.tv_sec) + (clock_f_end.tv_nsec - clock_f_start.tv_nsec)/10e9;
    T_sys_first = (f_end.ru_stime.tv_sec - f_start.ru_stime.tv_sec) + (f_end.ru_stime.tv_usec - f_start.ru_stime.tv_usec)/10e6;
    T_user_first = (f_end.ru_utime.tv_sec - f_start.ru_utime.tv_sec) + (f_end.ru_utime.tv_usec - f_start.ru_utime.tv_usec)/10e6;



    //heapsort para cada vetor
    getrusage(RUSAGE_SELF, &sec_start);
    clock_gettime(CLOCK_MONOTONIC, &clock_sec_start);
    functions::heapsort(v1,MAXTAM);
    functions::heapsort(v2,MAXTAM);
    functions::heapsort(v3,MAXTAM);
    functions::heapsort(v4,MAXTAM);
    functions::heapsort(v5,MAXTAM);
    functions::heapsort(v6,MAXTAM);
    functions::heapsort(v7,MAXTAM);
    functions::heapsort(v8,MAXTAM);
    getrusage(RUSAGE_SELF, &sec_end);
    clock_gettime(CLOCK_MONOTONIC, &clock_sec_end);
    
    //Calculando tempos para heapsort
    T_clock_second = (clock_sec_end.tv_sec - clock_sec_start.tv_sec) + (clock_sec_end.tv_nsec - clock_sec_start.tv_nsec)/10e9;
    T_sys_second = (sec_end.ru_stime.tv_sec - sec_start.ru_stime.tv_sec) + (sec_end.ru_stime.tv_usec - sec_start.ru_stime.tv_usec)/10e6;
    T_user_second = (sec_end.ru_utime.tv_sec - sec_start.ru_utime.tv_sec) + (sec_end.ru_utime.tv_usec - sec_start.ru_utime.tv_usec)/10e6;
    
    printf("Shellsort:\nTempo total de relogio: %lf\nTempo total de usuario: %lf\nTempo total de sistema: %lf\n",T_clock_first, T_user_first, T_sys_first);
    printf("Heapsort:\nTempo total relogio: %lf\nTempo total de usuario: %lf\nTempo total de sistema: %lf\n",T_clock_second,T_user_second, T_sys_second);


}