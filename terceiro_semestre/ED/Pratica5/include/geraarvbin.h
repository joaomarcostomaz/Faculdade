#ifndef Tree
#define Tree

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <getopt.h>
#include <string.h>
#include <math.h>

// Syntax tree structure
typedef long TipoChave;
typedef struct TipoRegistro {
  TipoChave Chave;
} TipoRegistro;
typedef struct TipoNo * TipoApontador;
typedef struct TipoNo {
  TipoRegistro Reg;
  TipoApontador Esq, Dir;
} TipoNo;

typedef struct prm{
  char nomesaida[200];
  int semente;
  int numno;
  FILE * saida;
  int treesize;
  int numlevel;
} prm_t;

void uso();
void parse_args(int argc, char ** argv, prm_t * prm);
void dumpTree(TipoApontador * T, int level, prm_t * prm);
int createTree(TipoNo ** curr, int level, prm_t * prm);
int ancestral(int i, int j, TipoNo *root, int size);
void pre_order(TipoNo* p, TipoRegistro *vector,int *idx);
void in_order(TipoNo* p, TipoRegistro *vector,int *idx);
void pos_order(TipoNo* p, TipoRegistro *vector,int *idx);




#endif