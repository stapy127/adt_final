#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  char Info;
  struct _Node *Next;
} Node;

Node* NewNode(char Item) {
  Node *n;
  n = (Node *)malloc(sizeof(Node));
  n -> Info = Item;
  n -> Next = NULL;
  return n;
}

void FreeNode(Node *n) {
  free(n);
}

void InsertFirst(Node *l, Node *n) {
  n -> Next = l;
  l = n;
}

void InsertAfter(Node *p, Node *n) {
  n -> Next = p -> Next;
  p -> Next = n;
}

void InsertLast(Node *l, Node *n) {
  Node *p = l;
  while(p -> Next != NULL) {
    p = p -> Next;
  }
  p -> Next = n;
}

Node* DeleteFirst(Node *l) {
  Node *n;
  n = l;
  l = l -> Next;
  n -> Next = NULL;
  return n;
}

Node* DeleteAfter(Node *p) {
  Node *n;
  n = p -> Next;
  p -> Next = n -> Next;
  n -> Next = NULL;
  return n;
}

Node* DeleteLast(Node *l) {
  Node *p = l;
  Node *n;
  while(p -> Next != NULL) {
    n = p;
    p = p -> Next;
  }
  n -> Next = NULL;
  return p;
}

void Traverse(Node *l) {
  Node *p;
  p = l;
  while(p != NULL) {
    // Do something with nodes
    p = p -> Next;
  }
}

void PrintInfo(Node *l) {
  Node *p;
  p = l;
  int counter = 0;
  while(p != NULL) {
    printf("%c ", p -> Info);
    counter++;
    p = p -> Next;
  }
  printf("\nTotal Nodes: %d\n", counter);
}

Node* SearchInfo(Node *l, char info) {
  Node *p;
  p = l;
  while(p -> Info != info && p != NULL) {
    p = p -> Next;
  }
  return p;
}

int main() {
  return 0;
}
