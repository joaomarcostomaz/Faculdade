#include "../include/AVL.h"

node * insert(node * T, int x, stat_t * st) {
  if (T == NULL) {
    T = (node * ) malloc(sizeof(node));
    T -> data = x;
    T -> left = NULL;
    T -> right = NULL;
  } else
  if (x > T -> data) // insert in right subtree
  {
    T -> right = insert(T -> right, x, st);
    if (BF(T) > 2){
      if (x > T -> right -> data){
        T = RR(T);
	st->RR++;
      } else{
        T = RL(T);
	st->RL++;
      }
    }
  } else
  if (x < T -> data) {
    T -> left = insert(T -> left, x, st);
    if (BF(T) > 2){
      if (x < T -> left -> data){
        T = LL(T);
	st->LL++;
      }else{
        T = LR(T);
	st->LR++;
      }
    }
  }
  T -> ht = height(T);
  return (T);
}

node * Delete(node * T, int x, stat_t * st) {
  node * p;
  if (T == NULL) {
    return NULL;
  } else
  if (x > T -> data) // insert in right subtree
  {
    T -> right = Delete(T -> right, x, st);
    if (BF(T) > 2){
      if (BF(T -> left) >= 0){
        T = LL(T);
	st->LL++;
      }
      else{
        T = LR(T);
	st->LR++;
      }
    }
  } else
  if (x < T -> data) {
    T -> left = Delete(T -> left, x, st);
    if (BF(T) > 2){ //Rebalance during windup
      if (BF(T -> right) <= 0){
        T = RR(T);
	st->RR++;
      }
      else{
        T = RL(T);
	st->RL++;
      }
    }
  } else {
    //data to be deleted is found
    if (T -> right != NULL) { //delete its inorder succesor
      p = T -> right;
      while (p -> left != NULL)
        p = p -> left;
      T -> data = p -> data;
      T -> right = Delete(T -> right, p -> data, st);
      if (BF(T) > 2){ //Rebalance during windup
        if (BF(T -> left) >= 0){
          T = LL(T);
	  st->LL++;
	}
        else{
          T = LR(T);\
	  st->LR++;
	}
      }
    } else
      return (T -> left);
  }
  T -> ht = height(T);
  return (T);
}

int height(node * T) {
  int lh, rh;
  if (T == NULL)
    return (0);
  if (T -> left == NULL)
    lh = 0;
  else
    lh = 1 + T -> left -> ht;
  if (T -> right == NULL)
    rh = 0;
  else
    rh = 1 + T -> right -> ht;
  if (lh > rh)
    return (lh);
  return (rh);
}

node * rotateright(node * x) {
  node * y;
  y = x -> left;
  x -> left = y -> right;
  y -> right = x;
  x -> ht = height(x);
  y -> ht = height(y);
  return (y);
}

node * rotateleft(node * x) {
  node * y;
  y = x -> right;
  x -> right = y -> left;
  y -> left = x;
  x -> ht = height(x);
  y -> ht = height(y);
  return (y);
}

node * RR(node * T) {
  T = rotateleft(T);
  return (T);
}

node * LL(node * T) {
  T = rotateright(T);
  return (T);
}

node * LR(node * T) {
  T -> left = rotateleft(T -> left);
  T = rotateright(T);
  return (T);
}

node * RL(node * T) {
  T -> right = rotateright(T -> right);
  T = rotateleft(T);
  return (T);
}

int BF(node * T) {
  int lh, rh;
  if (T == NULL)
    return (0);

  if (T -> left == NULL)
    lh = 0;
  else
    lh = 1 + T -> left -> ht;

  if (T -> right == NULL)
    rh = 0;
  else
    rh = 1 + T -> right -> ht;

  return (lh-rh);
}

void preorder(node * T) {
  if (T != NULL) {
    printf("%d(Bf=%d)", T -> data, BF(T));
    preorder(T -> left);
    preorder(T -> right);
  }
}

void inorder(node * T) {
  if (T != NULL) {
    inorder(T -> left);
    printf("%d(Bf=%d)", T -> data, BF(T));
    inorder(T -> right);
  }
}

void dump(node * T, int level,char * pref) {
  if (T != NULL) {
    printf("%s ",pref);
    for(int i=0; i<level; i++) printf("    ");
    printf("%3d (Bf=%d, H=%d)\n", T -> data, BF(T),T->ht);
    dump(T -> left,level+1,pref);
    dump(T -> right,level+1,pref);
  }
}
