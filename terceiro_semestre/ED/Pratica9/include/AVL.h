#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include <sys/time.h>

typedef struct stat{
  int RR;
  int LL;
  int RL;
  int LR;
} stat_t;

typedef struct node {
  int data;
  struct node * left, * right;
  int ht;
} node;

node * insert(node * , int, stat_t *);
node * Delete(node * , int, stat_t *);
void preorder(node * );
void inorder(node * );
void dump(node *, int, char* );
int height(node * );
node * rotateright(node * );
node * rotateleft(node * );
node * RR(node * );
node * LL(node * );
node * LR(node * );
node * RL(node * );
int BF(node * );