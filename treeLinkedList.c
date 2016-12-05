#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  int Info;
  struct _Node *Left;
  struct _Node *Right;
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

Node* MotherNode() {
  // can't do
}

Node* BrotherNode() {
  // can't do
}

void setLeft(Node *n, int Data) {
  Node *p;
  if(n -> Left != NULL) {
    p = NewNode(Data);
    n -> Left = p;
  } else {
    printf("Node Inused\n");
  }
}

void setRight(Node *n, int Data) {
  Node *p;
  if(n -> Left != NULL) {
    p = NewNode(Data);
    n -> Right = p;
  } else {
    printf("Node Inused\n");
  }
}

int main() {
  return 0;
}
