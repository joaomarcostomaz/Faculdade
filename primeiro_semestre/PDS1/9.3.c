#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{
    double sepal_length;
    double sepal_width;
    double petal_length;
    double petal_width;
    char flower_type[50];

}Iris;
int main(){
    int n; 
    scanf("%d", &n);
    void identified_flower(Iris flower[],int n);
    void nonidentified_flower(Iris non_identified);
    void classify_flower(Iris non_identified, Iris flower[], int n);

    Iris flowers[n];
    Iris non_identify;

    identified_flower(flowers,n);
    nonidentified_flower(non_identify);
    classify_flower(non_identify,flowers,n);

}
void classify_flower(Iris non_identified, Iris flower[], int n){
    char new_type[50];
    double minor = 99999999.9;

    for(int i = 0; i < n; i++){
        double check =  sqrt(
      pow(flower[i].petal_length - non_identified.petal_length, 2) +
      pow(flower[i].petal_width - non_identified.petal_width, 2) +
      pow(flower[i].sepal_length - non_identified.sepal_length, 2) +
      pow(flower[i].sepal_width - non_identified.sepal_width, 2)
    );
        printf("%lf", check);
        if(check < minor){
            minor = check;
            strcpy(new_type,flower[i].flower_type);
        }
        
    }
    printf("%s", new_type);

}
void identified_flower(Iris flower[],int n){
    for(int i = 0; i < n; i++){
        scanf("%lf",&flower[i].sepal_length);
        scanf("%lf",&flower[i].sepal_width);
        scanf("%lf",&flower[i].petal_length);
        scanf("%lf",&flower[i].petal_width);
        scanf("%s",flower[i].flower_type);
    }

}
void nonidentified_flower(Iris non_identified){
        scanf("%lf",&non_identified.sepal_length);
        scanf("%lf",&non_identified.sepal_width);
        scanf("%lf",&non_identified.petal_length);
        scanf("%lf",&non_identified.petal_width);
}
