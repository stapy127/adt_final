#include <stdio.h>
#define MAXTREE 100
typedef struct {
  int info;
  int used;
} Node;

typedef struct {
  Node node[MAXTREE];
} Tree;

void InitializeTree(Tree *t) {
  for(int i = 0; i < MAXTREE; i++) {
    t -> node[i].info = 0;
    t -> node[i].used = 0;
  }
}

void MakeTree(Tree *t, int Data) {
  InitializeTree(t);
  t -> node[0].info = Data;
  t -> node[0].used = 0;
}

int isLeft(int n) {
  if(n % 2 == 1)
    return 1;
  return 0;
}

int isRight(int n) {
  if(n % 2 == 0)
    return 1;
  return 0;
}

int LeftNode(int n) {
  return ((2 * n) + 1);
}

int RightNode(int n) {
  return (2 * (n + 1));
}

int MotherNode(int n) {
  return ((n-1) / 2);
}

int BrotherNode(int n) {
  if(isLeft(n)) {
    return RightNode(MotherNode(n));
  } else {
    return LeftNode(MotherNode(n));
  }
}

void setLeft(Tree *t, int n, int data) {
  int p;
  p = LeftNode(n);
  if(p < MAXTREE) {
    if(t -> node[p].used)
      printf("Node Inused\n");
    else {
      t -> node[p].info = data;
      t -> node[p].used = 1;
    }
  } else {
    printf("Tree Overflow\n");
  }
}

void setRight(Tree *t, int n, int data) {
  int p;
  p = RightNode(n);
  if(p < MAXTREE) {
    if(t -> node[p].used)
      printf("Node Inused\n");
    else {
      t -> node[p].info = data;
      t -> node[p].used = 1;
    }
  } else {
    printf("Tree Overflow\n");
  }
}

int main() {
  return 0;
}
