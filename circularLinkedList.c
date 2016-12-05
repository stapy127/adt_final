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
  Node *p = l;
  while(p -> Next != l) {
    p = p -> Next;
  }
  p -> Next = n;
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
  n -> Next = l;
}

Node* DeleteFirst(Node *l) {
  Node *n, *p;
  n = l;
  p = l;
  while(p -> Next != l) {
    p = p -> Next;
  }
  p -> Next = l -> Next;
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
  Node *n = l;
  Node *p;
  while(n -> Next != l) {
    p = n;
    n = n -> Next;
  }
  n -> Next = NULL;
  p -> Next = l;
  return n;
}

void Traverse(Node *l) {
  Node *p;
  p = l;
  do {
    // Do something with nodes
    p = p -> Next;
  } while(p -> Next != l);
}

void PrintInfo(Node *l) {
  Node *p;
  p = l;
  int counter = 0;
  do {
    printf("%c ", p -> Info);
    counter++;
    p = p -> Next;
  } while(p -> Next != l);
  printf("\nTotal Nodes: %d\n", counter);
}

Node* SearchInfo(Node *l, char info) {
  Node *p;
  p = l;
  if(p -> Info != info) {
    do {
      p = p -> Next;
    } while(p -> Info != info && p != l);
  }
  if(p == l) {
    p = NULL;
  }
  return p;
}

int main() {
  return 0;
}
