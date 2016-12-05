#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  int Info;
  struct _Node *Left;
  struct _Node *Right;
  struct _Node *Mother;
} Node;

Node* NewNode(int Data) {
  Node *n;
  n = (Node*)malloc(sizeof(Node));
  n -> Info = Data;
  return n;
}

void MakeTree(Node *tree, int Data) {
  Node *p;
  p = NewNode(Data);
  tree = p;
}

Node* LeftNode(Node *n) {
  return n -> Left;
}

Node* RightNode(Node *n) {
  return n -> Right;
}

int isLeft(Node *n) {
  return n -> Mother -> Left == n;
}

int isRight(Node *n) {
  return n -> Mother -> Right == n;
}

Node* MotherNode(Node *n) {
  return n -> Mother;
}

Node* BrotherNode(Node *n) {
  if(isLeft(n)) {
    return n -> Mother -> Right;
  } else {
    return n -> Mother -> Left;
  }
}

void setLeft(Node *n, int Data) {
  Node *p;
  if(n -> Left != NULL) {
    p = NewNode(Data);
    n -> Left = p;
    p -> Mother = n;
  } else {
    printf("Node Inused\n");
  }
}

void setRight(Node *n, int Data) {
  Node *p;
  if(n -> Left != NULL) {
    p = NewNode(Data);
    n -> Right = p;
    p -> Mother = n;
  } else {
    printf("Node Inused\n");
  }
}

int main() {
  return 0;
}
