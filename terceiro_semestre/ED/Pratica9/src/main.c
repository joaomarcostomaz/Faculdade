#include "../include/AVL.h"

int main(int argc, char * argv[]) {
  stat_t st;
  node * root = NULL;
  int x, op;
  int i,n;
  char pref[100] = "";

  do {
    printf("\n1)Create:");
    printf("\n2)Insert:");
    printf("\n3)Delete:");
    printf("\n4)Print:");
    printf("\n5)Quit:");
    printf("\n\nEnter Your Choice:");
    scanf("%d", & op);
    switch (op) {
    case 1:
      printf("\nEnter no. of elements:");
      scanf("%d", & n);
      printf("\nEnter tree data:");
      root = NULL;
      for (i = 0; i < n; i++) {
        scanf("%d", & x);
	printf("\nInsert %d\n",x);
        root = insert(root, x, &st);
	dump(root,0,pref);
      }
      break;
    case 2:
      printf("\nEnter a data:");
      scanf("%d", & x);
      root = insert(root, x, &st);
      break;
    case 3:
      printf("\nEnter a data:");
      scanf("%d", & x);
      root = Delete(root, x, &st);
      break;
    case 4:
      printf("\nPreorder sequence:\n");
      preorder(root);
      printf("\n\nInorder sequence:\n");
      inorder(root);
      printf("\n");
      printf("\n\nDump:\n");
      dump(root,0,pref);
      break;
    }
  } while (op != 5);
  return 0;
}
