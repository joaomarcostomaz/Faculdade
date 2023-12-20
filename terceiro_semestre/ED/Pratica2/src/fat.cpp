#include <iostream>
#include "../include/fat.hpp"
#include <sys/time.h>
#include <sys/resource.h>

int getrusage(int who, struct rusage *usage);

using namespace std;


int main(int argc, char **argv){
    struct timespec clock_f_start, clock_f_end, clock_sec_start, clock_sec_end;
    struct rusage f_start, f_end, sec_start, sec_end; 
    int first_result, second_result, idx=1;
    double T_sys_first = 0, T_user_first = 0, T_clock_first = 0, T_sys_second = 0, T_user_second = 0, T_clock_second = 0;
    double t_sys_first, t_user_first, t_clock_first, t_sys_second, t_user_second, t_clock_second;
    while(idx <= 5){ 

        //Fazendo o código para o recursivo! 
        getrusage(RUSAGE_SELF, &f_start);
        clock_gettime(CLOCK_MONOTONIC, &clock_f_start);
        first_result = fat(idx);
        getrusage(RUSAGE_SELF, &f_end);
        clock_gettime(CLOCK_MONOTONIC, &clock_f_end);

        //Tempo do algoritmo para 1 chamada
        t_clock_first = (clock_f_end.tv_sec - clock_f_start.tv_sec) + (clock_f_end.tv_nsec - clock_f_start.tv_nsec)/10e9;
        t_sys_first = (f_end.ru_stime.tv_sec - f_start.ru_stime.tv_sec) + (f_end.ru_stime.tv_usec - f_start.ru_stime.tv_usec)/10e6;
        t_user_first = (f_end.ru_utime.tv_sec - f_start.ru_utime.tv_sec) + (f_end.ru_utime.tv_usec - f_start.ru_utime.tv_usec)/10e6;

        printf("Tempo de usuario: %lf\nTempo de sistema: %lf\nTempo de relogio: %lf\nFatorial recursivo de: %d\n", t_user_first, t_sys_first, t_clock_first, idx);

        //Tempo total primeiro algoritmo
        T_clock_first = T_clock_first + t_clock_first;
        T_sys_first = T_sys_first + t_sys_first;
        T_user_first = T_user_first + t_user_first;

        //Código para o algoritmo iterativo
        getrusage(RUSAGE_SELF, &sec_start);
        clock_gettime(CLOCK_MONOTONIC, &clock_sec_start);
        second_result = fat_iterativo(idx);
        getrusage(RUSAGE_SELF, &sec_end);
        clock_gettime(CLOCK_MONOTONIC, &clock_sec_end);

        //Tempo para 1 chamada
        t_clock_second = (clock_sec_end.tv_sec - clock_sec_start.tv_sec) + (clock_sec_end.tv_nsec - clock_sec_start.tv_nsec)/10e9;
        t_sys_second = (sec_end.ru_stime.tv_sec - sec_start.ru_stime.tv_sec) + (sec_end.ru_stime.tv_usec - sec_start.ru_stime.tv_usec)/10e6;
        t_user_second = (sec_end.ru_utime.tv_sec - sec_start.ru_utime.tv_sec) + (sec_end.ru_utime.tv_usec - sec_start.ru_utime.tv_usec)/10e6;

        printf("Tempo de usuario: %lf\nTempo de sistema: %lf\nTempo de relogio: %lf\nFatorial iterativo de: %d\n", t_user_second, t_sys_second, t_clock_second, idx);

        //Tempo total segundo algoritmo
        T_clock_second = T_clock_second + t_clock_second;
        T_sys_second = T_sys_second + t_sys_second;
        T_user_second = T_user_second + t_user_second;

        idx++;

    }
    printf("Tempo total de usuario: %lf\nTempo total de sistema: %lf\nTempo total de relogio: %lf\nFatorial recursivo no intervalo de 1 a %d\n", T_user_first, T_sys_first, T_clock_first, idx);
    printf("Tempo total usuario: %lf\nTempo total de sistema: %lf\nTempo total de relogio: %lf\nFatorial iterativo no intervalo de 1 a %d\n", T_user_second, T_sys_second, T_clock_second, idx);
}