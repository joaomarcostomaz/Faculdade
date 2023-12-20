#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  double sepal_length;
  double sepal_width;
  double petal_length;
  double petal_width;
  char type[50];
} Iris;


void classify(Iris not_identify, Iris flowers[], int N) {
  double mini = 99999999.9;
  char type[50];

  for(int i = 0; i < N; i++) {
    double value = sqrt(
      pow(flowers[i].petal_length - not_identify.petal_length, 2) +
      pow(flowers[i].petal_width - not_identify.petal_width, 2) +
      pow(flowers[i].sepal_length - not_identify.sepal_length, 2) +
      pow(flowers[i].sepal_width - not_identify.sepal_width, 2)
    );

    if(value < mini) {
      mini = value;
      strcpy(type, flowers[i].type);
    }
  }

  printf("%s", type);
}


int main() {
  int N;
  scanf("%d", &N);

  Iris flowers[N];

  for(int i = 0; i < N; i++) {
    scanf(
      "%lf %lf %lf %lf %s",
      &flowers[i].sepal_length,
      &flowers[i].sepal_width,
      &flowers[i].petal_length,
      &flowers[i].petal_width,
      flowers[i].type
    );
  }

  Iris aditional;

  scanf(
    "%lf %lf %lf %lf",
    &aditional.sepal_length,
    &aditional.sepal_width,
    &aditional.petal_length,
    &aditional.petal_width
  );

  classify(aditional, flowers, N);
}