#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <getopt.h>
#include <string.h>
#include <math.h>
#include "../include/geraarvbin.h"


void uso()
// Descricao: imprime as instrucoes de uso do programa
// Entrada:  N/A
// Saida: instrucoes
{
  fprintf(stderr,"geraexp\n");
  fprintf(stderr,"\t-o <arq>\t(arquivo de saida) \n");
  fprintf(stderr,"\t-s <num>\t(semente)\n");
  fprintf(stderr,"\t-n <num>\t(numero de nos)\n");
  fprintf(stderr,"\t-h\t(opcoes de uso)\n");
}

void parse_args(int argc, char ** argv, prm_t * prm)
// Descricao: analisa a linha de comando a inicializa variaveis
// Entrada: argc e argv
// Saida: prm
{
     extern char * optarg;
     extern int optind;
     int c ;
     // valores padrao
     prm->nomesaida[0] = 0;
     prm->semente = 0;
     prm->numno = 3;
     prm->numlevel = 2;
     // percorre a linha de comando buscando identificadores
     while ((c = getopt(argc, argv, "o:s:n:iph")) != EOF){
       switch(c) {
         case 'o':
	          // arquivo de saida
	          strcpy(prm->nomesaida,optarg);
                  break;
         case 's':
	          // semente aleatoria
	          prm->semente = atoi(optarg);
		  srand48((long) prm->semente);
		  break;
         case 'n':
	          // numero de nos
	          prm->numno = atoi(optarg);
		  prm->numlevel = ((int) log2((double) prm->numno))+2;
		  break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
     }
     // verifica apenas o nome do arquivo de saida
     if (!prm->nomesaida[0]) {
       printf("Arquivo de saida nao definido.");
       exit(1);
     }
}

void dumpTree(TipoApontador * T, int level, prm_t * prm) {
  if ((*T) != NULL) {
    for(int i=0; i<level; i++) fprintf(prm->saida,"    ");
    fprintf(prm->saida," %3ld (%d)\n", (*T)->Reg.Chave,level);
    dumpTree(&(*T)->Esq,level+1,prm);
    dumpTree(&(*T)->Dir,level+1,prm);
  }
}

int createTree(TipoNo ** curr, int level, prm_t * prm){
  // create node
  (*curr) = (TipoNo*) malloc(sizeof(TipoNo));
  (*curr)->Esq = (*curr)->Dir = NULL;
  // set type
  if (drand48()>((8.0*(1<<level)*prm->treesize))/(((1<<prm->numlevel)*prm->numno))){
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
    if (prm->treesize<prm->numno) createTree(&((*curr)->Esq),level+1,prm);
    if (prm->treesize<prm->numno) createTree(&((*curr)->Dir),level+1,prm);
  } else {
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
  }
  return prm->treesize;
}
void pre_order(TipoNo* p, TipoRegistro *vector, int *idx){
    if(p != NULL){
      vector[(*idx)++] = p->Reg;
      pre_order(p->Esq,vector,idx);
      pre_order(p->Dir,vector,idx);
    }
}
void in_order(TipoNo* p, TipoRegistro *vector, int *idx){
    if(p != NULL){
      pre_order(p->Esq,vector,idx);
      vector[(*idx)++] = p->Reg;
      pre_order(p->Dir,vector,idx);
    }
}
void pos_order(TipoNo* p, TipoRegistro *vector, int *idx){
    if(p != NULL){
      pre_order(p->Esq,vector,idx);
      pre_order(p->Dir,vector,idx);
      vector[(*idx)++] = p->Reg;
    }
}

int ancestral(int i, int j, TipoNo *root, int size){
  
  TipoRegistro* vector1 = (TipoRegistro*)malloc(size * sizeof(TipoRegistro));
  TipoRegistro* vector2 = (TipoRegistro*)malloc(size * sizeof(TipoRegistro));
  int index = 0;
  int aux1[size], aux2[size];
  int position1,position2;
  int l = 0, soma = 0;

  pre_order(root, vector1, index);
  index = 0;
  pos_order(root,vector2,index);

  for(int k = 0; k < size; k++){
    if (vector1[k].Chave == i){
      position1 = k;
    }
  }
  for(int k = position1 + 1; k < size; k++){
    aux1[l] = vector1[k].Chave;
    l++;
  }
  l = 0;
  for(int k = 0; k < size; k++){
    if (vector2[k].Chave == i){
      position2 = k;
    }
  }
  for(int k = position2 + 1; k > 0; k--){
    aux2[l] = vector2[k].Chave;
    l++;
  }
  l = 0;
  for(int k = 0; k < size; k++){
    if(aux1[k] == j){
      soma += 1;
    }
    if(aux2[k] == j){
      soma += 1;
    }
  }
  if(soma == 2){
    return 1;
  }else{
    return 0;
  }
}


