#include <stdio.h>

int main(void) {
  int n, i, fact;
  fact = 1;

  printf("Positive integer:");
  scanf("%d", &n);
  
  for(i = 1; i<=n; i++) 
    fact = fact*i;

  printf("Factorial %d = %d\n", n, fact);
}
