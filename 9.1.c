#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    int day;
    int month;
    int year;
} Date;

typedef struct{
    char name[100];
    char local[100];
    Date date;

}event;

int main(){
    int n;
    void register_event(event schedule[], int n);
    void print_event(event schedule[],Date d, int n);

    scanf("%d", &n);
    event schedule[n];
    register_event(schedule,n);
    Date data;
    scanf("%d %d %d", &data.day, &data.month, &data.year);
    print_event(schedule,data,n);
}
void register_event(event schedule[], int n){
    for(int i = 0; i < n; i++){
        scanf("%s", schedule[i].name);
        scanf("%s", schedule[i].local);
        scanf("%d", &schedule[i].date.day);
        scanf("%d", &schedule[i].date.month);
        scanf("%d", &schedule[i].date.year);
    }
}
void print_event(event schedule[],Date d, int n){
    int exist = 0;
    for(int i = 0; i < n; i++){
        Date check = schedule[i].date;
        if(d.day == check.day && d.month == check.month && d.year == check.year){
            exist++;
            printf("%s %s\n", schedule[i].name, schedule[i].local);
        }
    }
    if(exist == 0){
        printf("Nenhum evento encotrando!");
    }
}