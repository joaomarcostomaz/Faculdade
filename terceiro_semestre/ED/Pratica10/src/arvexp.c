#include<stdlib.h>
#include<stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

#ifndef CARGA
#define CARGA 100
#endif

#ifndef m
#define m               2
#endif
#define mm              (m * 2)
#define FALSE           0
#define TRUE            1

#define MAXCH 100


typedef long TipoChave;

typedef struct Registro {
  TipoChave Chave;
  char Carga[CARGA];
} Registro;

typedef struct Pagina* Apontador;

typedef struct Pagina {
  short n;
  Registro r[mm];
  Apontador p[mm + 1];
} Pagina;

typedef struct stat{
  int X;
  int curr;
  Pagina p[3];
}stat_t;


void Inicializa(Apontador *Dicionario)

{  *Dicionario = NULL;
}

void Pesquisa(Registro *x, Apontador Ap)
{ long i = 1;
  if (Ap == NULL) 
  { 
    x->Chave = -1;
    //printf("Registro nao esta presente na arvore\n");
    return;
  }
  while (i < Ap->n && x->Chave > Ap->r[i-1].Chave) i++;
  if (x->Chave == Ap->r[i-1].Chave) 
    { *x = Ap->r[i-1];
      return;
    }
  if (x->Chave < Ap->r[i-1].Chave)
    Pesquisa(x, Ap->p[i-1]);
  else
    Pesquisa(x, Ap->p[i]);
} 

void InsereNaPagina(Apontador Ap, Registro Reg, Apontador ApDir)
{ short NaoAchouPosicao;
  int k;
  k = Ap->n;
  NaoAchouPosicao = (k > 0);
  while (NaoAchouPosicao) 
    { if (Reg.Chave >= Ap->r[k-1].Chave) 
      { NaoAchouPosicao = FALSE;
        break;
      }
      Ap->r[k] = Ap->r[k-1];
      Ap->p[k+1] = Ap->p[k];
      k--;
      if (k < 1)  NaoAchouPosicao = FALSE;
    }
  Ap->r[k] = Reg;
  Ap->p[k+1] = ApDir;
  Ap->n++;
} 

void Ins(Registro Reg, Apontador Ap, short *Cresceu, 
	 Registro *RegRetorno,  Apontador *ApRetorno)
{ long i = 1;
  long j;
  Apontador ApTemp;
  if (Ap == NULL) 
  { *Cresceu = TRUE; (*RegRetorno) = Reg; (*ApRetorno) = NULL;
    return;
  }
  while (i < Ap->n && Reg.Chave > Ap->r[i-1].Chave)  i++;
  if (Reg.Chave == Ap->r[i-1].Chave) 
  { //printf(" Erro: Registro ja esta presente %ld\n",Reg.Chave); i
    *Cresceu = FALSE;
    return;
  }
  if (Reg.Chave < Ap->r[i-1].Chave)
  i--;
  Ins(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno);
  if (!*Cresceu)
  return;
  if (Ap->n < mm)   /* Pagina tem espaco */
    { InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
      *Cresceu = FALSE;
      return;
    }
  /* Overflow: Pagina tem que ser dividida */
  ApTemp = (Apontador)malloc(sizeof(Pagina));
  ApTemp->n = 0;  ApTemp->p[0] = NULL;
  if (i < m+1) 
    { InsereNaPagina(ApTemp, Ap->r[mm-1], Ap->p[mm]);
      Ap->n--;
      InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
    } 
  else
    InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);
  for (j = m + 2; j <= mm; j++)
    InsereNaPagina(ApTemp, Ap->r[j-1], Ap->p[j]);
  Ap->n = m;  ApTemp->p[0] = Ap->p[m+1];
  *RegRetorno = Ap->r[m];
  *ApRetorno = ApTemp;
}

void Insere(Registro Reg, Apontador *Ap)

{ short Cresceu;
  Registro RegRetorno;
  Pagina *ApRetorno, *ApTemp;

  Ins(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);
  if (Cresceu)  /* Arvore cresce na altura pela raiz */
  { ApTemp = (Pagina *)malloc(sizeof(Pagina));
    ApTemp->n = 1;
    ApTemp->r[0] = RegRetorno;
    ApTemp->p[1] = ApRetorno;
    ApTemp->p[0] = *Ap;
    *Ap = ApTemp;
  }
}

void Reconstitui(Apontador ApPag, Apontador ApPai, int PosPai, short *Diminuiu)

{ Pagina *Aux;
  long DispAux, j;
  if (PosPai < ApPai->n)   /* Aux = Pagina a direita de ApPag */
  { Aux = ApPai->p[PosPai+1];
    DispAux = (Aux->n - m + 1) / 2;
    ApPag->r[ApPag->n] = ApPai->r[PosPai];
    ApPag->p[ApPag->n + 1] = Aux->p[0];
    ApPag->n++;
    if (DispAux > 0)  /* Existe folga: transfere de Aux para ApPag */
    { for (j = 1; j < DispAux; j++)
        InsereNaPagina(ApPag, Aux->r[j-1], Aux->p[j]);
      ApPai->r[PosPai] = Aux->r[DispAux-1];
      Aux->n -= DispAux;
      for (j = 0; j < Aux->n; j++)  Aux->r[j]   = Aux->r[j + DispAux];
      for (j = 0; j <= Aux->n; j++)	Aux->p[j] = Aux->p[j + DispAux];
      *Diminuiu = FALSE;
    }
    else
      { /* Fusao: intercala Aux em ApPag e libera Aux */
        for (j = 1; j <= m; j++)
	  InsereNaPagina(ApPag, Aux->r[j-1], Aux->p[j]);
	free(Aux);
        for (j = PosPai + 1; j < ApPai->n; j++) 
	  { ApPai->r[j-1] = ApPai->r[j]; ApPai->p[j] = ApPai->p[j+1]; }
	ApPai->n--;
	if (ApPai->n >= m)
	*Diminuiu = FALSE;
      }
  }
  else
    { /* Aux = Pagina a esquerda de ApPag */
      Aux = ApPai->p[PosPai-1];
      DispAux = (Aux->n - m + 1) / 2;
      for (j = ApPag->n; j >= 1; j--) ApPag->r[j] = ApPag->r[j-1];
      ApPag->r[0] = ApPai->r[PosPai-1];
      for (j = ApPag->n; j >= 0; j--) ApPag->p[j+1] = ApPag->p[j];
      ApPag->n++;
      if (DispAux > 0)   /* Existe folga: transfere de Aux para ApPag */
	{ for (j = 1; j < DispAux; j++)
	    InsereNaPagina(ApPag, Aux->r[Aux->n - j], Aux->p[Aux->n - j + 1]);
	  ApPag->p[0] = Aux->p[Aux->n - DispAux + 1];
	  ApPai->r[PosPai-1] = Aux->r[Aux->n - DispAux];
	  Aux->n -= DispAux;
	  *Diminuiu = FALSE;
	}
      else
	{ /* Fusao: intercala ApPag em Aux e libera ApPag */
	  for (j = 1; j <= m; j++)
	    InsereNaPagina(Aux, ApPag->r[j-1], ApPag->p[j]);
          free(ApPag);
	  ApPai->n--;
	  if (ApPai->n >= m)  *Diminuiu = FALSE;
    
	}
    }
}

void Antecessor(Apontador Ap, int Ind, Apontador ApPai, short *Diminuiu)
{ if (ApPai->p[ApPai->n] != NULL) 
  { Antecessor(Ap, Ind, ApPai->p[ApPai->n], Diminuiu);
    if (*Diminuiu)
      Reconstitui(ApPai->p[ApPai->n], ApPai, (long)ApPai->n, Diminuiu);
    return;
  }
  Ap->r[Ind-1] = ApPai->r[ApPai->n - 1]; ApPai->n--; *Diminuiu = (ApPai->n < m);
} 

void Ret(TipoChave Ch, Apontador *Ap, short *Diminuiu)

{ long j, Ind = 1;
  Apontador Pag;
  if (*Ap == NULL) 
    { //printf("Erro: registro nao esta na arvore\n"); i
      *Diminuiu = FALSE;
      return;
    }
  Pag = *Ap;
  while (Ind < Pag->n && Ch > Pag->r[Ind-1].Chave) Ind++;
  if (Ch == Pag->r[Ind-1].Chave) 
  { if (Pag->p[Ind-1] == NULL)   /* Pagina folha */
    { Pag->n--;
      *Diminuiu = (Pag->n < m);
      for (j = Ind; j <= Pag->n; j++) 
        { Pag->r[j-1] = Pag->r[j];	Pag->p[j] = Pag->p[j+1]; }
      return;
    }
    /* Pagina nao e folha: trocar com antecessor */
    Antecessor(*Ap, Ind, Pag->p[Ind-1], Diminuiu);
    if (*Diminuiu)
      Reconstitui(Pag->p[Ind-1], *Ap, Ind - 1, Diminuiu);
    return;
  }
  if (Ch > Pag->r[Ind-1].Chave) Ind++;
  Ret(Ch, &Pag->p[Ind-1], Diminuiu);
  if (*Diminuiu)
  Reconstitui(Pag->p[Ind-1], *Ap, Ind - 1, Diminuiu);
}  

void Retira(TipoChave Ch, Apontador *Ap)

{ short Diminuiu;
  Apontador Aux;
  Ret(Ch, Ap, &Diminuiu);
  if (Diminuiu && (*Ap)->n == 0)  /* Arvore diminui na altura */
  { Aux = *Ap;   *Ap = Aux->p[0]; free(Aux);}
}  

void ImprimeI(Apontador p, int nivel, FILE * out, stat_t * st, char * pref)

{ long i;
  int stcapture=0;

  if (p == NULL)
  return;
  fprintf(out,"%s Nivel %d : ", pref,nivel);
  for (i = 0; i < p->n; i++){
    fprintf(out,"%ld ",(long)p->r[i].Chave);
    if ((p->r[i].Chave == st->X) && (st->curr >=0)){
      stcapture = 1;
    }
  }
  fprintf(out,"\n");
  if (stcapture){
    st->p[st->curr].n = p->n;
    for (i = 0; i < p->n; i++){
      st->p[st->curr].r[i].Chave = p->r[i].Chave;
    }
  }
  nivel++;
  for (i = 0; i <= p->n; i++)
    ImprimeI(p->p[i], nivel,out, st, pref);
} 

void Imprime(Apontador p,FILE * out, stat_t * st, char * pref)

{ int  n = 0;
  ImprimeI(p, n, out,st, pref);
} 

void TestaI(Apontador p, int pai, short direita)

{ int i;
  int antecessor = 0;
  if (p == NULL)
  return;
  if (p->r[0].Chave > pai && direita == FALSE) 
  { printf("Erro: filho %12ld maior que pai %d\n", p->r[0].Chave, pai);
    return;
  }
  for (i = 0; i < p->n; i++) 
    { if (p->r[i].Chave <= antecessor) 
      { printf("Erro: irmao %ld maior que irmao a esquerda %d\n",
	(long)p->r[i].Chave, antecessor);
        return;
      }
      antecessor = p->r[i].Chave;
    }
  for (i = 0; i < p->n; i++) 
    TestaI(p->p[i], p->r[i].Chave, FALSE);
  TestaI(p->p[p->n], p->r[i].Chave, TRUE);
}

void Testa(Apontador p)

{ int i;
  if (p == NULL)
    return;
  for (i = 0; i < p->n; i++) 
    TestaI(p->p[i], p->r[i].Chave, FALSE);
  TestaI(p->p[p->n], p->r[i].Chave, TRUE);
}

typedef struct exp{
  int numops;
  float op[3];
  int maxch; 
  int seed;
  int print;
} exp_t;

#define PESQUISA 0
#define INSERE 1
#define RETIRA 2

int main(int argc, char *argv[]) { 
  Registro x;
  Pagina *D;
  stat_t st;
  exp_t exp;

  int i, j, op;

  struct timespec clock_f_start, clock_f_end;
  struct rusage f_start, f_end; 
  double T_clock;

  exp.print = 0;
  exp.seed = 1;
  exp.numops = 1000;
  exp.maxch = 100;
  exp.op[PESQUISA] = 0.4;
  exp.op[INSERE] = 0.7;
  exp.op[RETIRA] = 1.0;

  srand48((unsigned int)exp.seed);

  getrusage(RUSAGE_SELF, &f_start);
  clock_gettime(CLOCK_MONOTONIC, &clock_f_start);

  Inicializa(&D);

  for (i=0; i<exp.numops; i++){
    // define op
    double opaux = drand48();
    for (op=0; op<3; op++){
      if (opaux<exp.op[op]){ break; }
    }
    
    // define chave
    x.Chave = (long)(exp.maxch*drand48());

    if (exp.print){
      printf("i %d opaux %f op %d x %ld\n",i,opaux,op,x.Chave);
    }

    switch (op){
      case PESQUISA:
           Pesquisa(&x,D); 
           break;
      case INSERE:
           Insere(x,&D); 
           break;
      case RETIRA:
           Retira(x.Chave, &D);
           break;
    }
    if (exp.print) Imprime(D,stdout,&st,"");
  }
  getrusage(RUSAGE_SELF, &f_end);
  clock_gettime(CLOCK_MONOTONIC, &clock_f_end);

  T_clock = (clock_f_end.tv_sec - clock_f_start.tv_sec) + (clock_f_end.tv_nsec - clock_f_start.tv_nsec) / 1000000000.0;

  printf("Tempo: %f\n", T_clock);

  return 0;
}