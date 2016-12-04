#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 10
typedef struct {
  int front;
  int rear;
  char QueueItem[MAXQUEUE];
} Queue;

void InitializeQueue(Queue *q) {
  for(int i = 0; i < MAXQUEUE; i++) {
    q -> QueueItem[i] = '\0';
  }
  q -> front = 0;
  q -> rear = 0;
}

int EmptyQueue(Queue *q) {
  return q -> front == q -> rear;
}

int FullQueue(Queue *q) {
  return q -> rear == MAXQUEUE;
}

int Insert(Queue *q, char item) {
  if(FullQueue(q)) {
    printf("Queue Overflow\n");
    return 0;
  } else {
    q -> QueueItem[(q -> rear)++] = item;
    return 1;
  }
}

int Delete(Queue *q, char *item) {
  if(EmptyQueue(q)) {
    printf("Queue Underflow\n");
    *item = '\0';
    return 0;
  } else {
    *item = q -> QueueItem[(q -> front)++];
    return 1;
  }
}

int main() {
  char items[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
  Queue *myQueue = (Queue*)malloc(sizeof(Queue));
  InitializeQueue(myQueue);

  for(int i = 0; i < sizeof(items); i++) {
    Insert(myQueue, items[i]);
  }

  char item;
  Delete(myQueue, &item);
  printf("deleted %c\n", item);
  // print item in queue
  for(int i = myQueue -> front; i < myQueue -> rear; i++) {
    printf("%c ", myQueue -> QueueItem[i]);
  }
  printf("\n");
}
