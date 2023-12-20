#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *p;

  p = (char *) malloc(19);
  free(p);
  p = (char *) malloc(12);
  free(p);
  p = (char *) malloc(16);
  free(p);

  return 0;
}

