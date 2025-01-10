/*
Queue
  Similar to stack, queue is a specialized type of an ordered list.
  One end is called front, The other end is called rear(or back).
  Additions and removals are done at the rear only.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int *arr;
  int front;
  int back;
  int size;
  int cnt;
}Queue;

void initQueue(Queue *q, int size);
void push(Queue *q, int value);
int pop(Queue *q);
int front(Queue *q);
int back(Queue *q);
bool isEmpty(Queue *q);
int size(Queue *q);
void resize(Queue *q);
void destroyQueue(Queue *q);

void initQueue(Queue *q, int size){
  q->arr = (int*)malloc(size * sizeof(int));
  if(q->arr == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  q->size = size; 
  q->front = 0;
  q->back = -1;
  q->cnt = 0;
}

void resize(Queue *q){
  int newSize = q->size * 2;
  int *newArr = (int*)malloc(newSize * sizeof(int));
  if(newArr == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  for(int i = 0; i < q->cnt; i++){
    newArr[i] = q->arr[(q->front + i) % q->size];
  }

  free(q->arr);
  q->arr = newArr;
  q->front = 0;
  q->back = q->cnt -1;
  q->size = newSize;
}

void push(Queue *q, int value){
  if(q->cnt == q->size) resize(q);
  
  q->back = (q->back + 1) % q->size;
  q->arr[q->back] = value;
  q->cnt++;
}

int pop(Queue *q){
  if(isEmpty(q)){
    fprintf(stderr, "Queue underflow\n");
    exit(1);
  }

  int value = q->arr[q->front];
  q->front = (q->front + 1) % q->size;
  q->cnt--;
  return value;
}

int front(Queue *q){
  if(isEmpty(q)){
    fprintf(stderr, "Queue is empty\n");
    exit(1);
  }

  return q->arr[q->front];
}

int back(Queue *q){
  if(isEmpty(q)){
    fprintf(stderr, "Queue is empty\n");
    exit(1);
  }

  return q->arr[q->back];
}

bool isEmpty(Queue *q){
  return q->cnt == 0;
}

int size(Queue *q){
  return q->cnt;
}

void destroyQueue(Queue *q){
  free(q->arr);
  q->arr = NULL;
  q->size = 0;
  q->front = 0;
  q->back = -1;
  q->cnt = 0;
}

int main(){
  Queue q;
  initQueue(&q, 4);

  push(&q, 10);
  push(&q, 20);
  push(&q, 30);
  push(&q, 40);
  push(&q, 50);
  push(&q, 60);

  printf("Front: %d\n", front(&q));
  printf("Back: %d\n", back(&q));
  printf("Queue size: %d\n", size(&q));

  while(!isEmpty(&q)){
    printf("Popped: %d\n", pop(&q));
  }

  destroyQueue(&q);
  return 0;
}