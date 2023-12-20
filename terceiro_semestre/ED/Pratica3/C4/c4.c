#include <stdlib.h>
struct Matrix
{
int rows, cols;
int** data;
};
struct Matrix* rotation3D=0;
int main(){
  int i;
  char * text;
  struct Matrix * rotation3D;
//rotation3D = (struct Matrix*) malloc(sizeof(struct Matrix));
rotation3D->rows=4;
rotation3D->cols=4;
rotation3D->data=(int**) malloc(sizeof(int*)*rotation3D->rows);
for(i=0;i<rotation3D->rows;i++)
rotation3D->data[i]=(int*) malloc(sizeof(int)*rotation3D->cols);
free(text);
//for(i=0;i<rotation3D->rows;i++)
// free(rotation3D->data[i]);
free(rotation3D->data);
free(rotation3D);
return 0;
}

