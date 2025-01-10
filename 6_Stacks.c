/*
Stack: A specialized type of an ordered list.
One end is called top, The other end is called bottom.
Additions to and removals from the top end only.

Ordered Lists
  One of the simplest abstract data types.
  Object: list of items that have a certain order
  ex: Chronologically ordered list
*/

//ex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int cnt;
  int *arr;
  int size;
}Stack;

void initStack(Stack *s, int size);
void push(Stack *s, int value);
void resize(Stack *s);
int pop(Stack *s);
int top(Stack *s);
bool isEmpty(Stack *s);
int size(Stack *s);
void destroy(Stack *s);

void initStack(Stack *s, int size){
  s->arr = (int*)malloc(size * sizeof(int));
  if(s->arr == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  s->size = size;
  s->cnt = 0;
}

void resize(Stack *s){
  int newSize = s->size * 2;
  int *newArr = (int*)malloc(newSize * sizeof(int));

  if(newArr == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  for(int i = 0; i < s->cnt; i++){
    newArr[i] = s->arr[i];
  }

  free(s->arr);
  s->arr = newArr;
  s->size = newSize;
}

void push(Stack *s, int value){
  if(s->cnt == s->size){
    resize(s);
  }
  s->arr[s->cnt++] = value;
}

int pop(Stack *s){
  if(isEmpty(s)){
    fprintf(stderr, "Stack underflow\n");
    exit(1);
  }

  return s->arr[--s->cnt];
}

int top(Stack *s){
  if(isEmpty(s)){
    fprintf(stderr, "Stack is empty\n");
    exit(1);
  }
  return s->arr[s->cnt -1];
}

bool isEmpty(Stack *s){
  return s->cnt==0;
}

int size(Stack *s){
  return s->cnt;
}

void destroy(Stack *s){
  free(s->arr);
  s->arr = NULL;
  s->size = 0;
  s->cnt = 0;
}

int main(){
  Stack s;
  initStack(&s, 4);

  push(&s, 10);
  push(&s, 20);
  push(&s, 30);
  push(&s, 40);
  push(&s, 50);
  push(&s, 60);

  printf("Top element: %d\n", top(&s));
  printf("Stack size: %d\n", size(&s));

  while(!isEmpty(&s)){
    printf("Popped: %d\n", pop(&s));
  }

  destroy(&s);
  return 0;
}