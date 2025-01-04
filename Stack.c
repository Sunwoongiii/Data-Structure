#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
  int cnt;
  int *arr;
  int front;
  int back;
  int size;
}Stack;

void initStack(Stack *s, int);
void push(Stack *s, int);
void resize(Stack *s);
int pop(Stack *s);
int front(Stack *s);
int Back(Stack *s);
bool isEmpty(Stack *s);
int size(Stack *s); 
void destroy(Stack *s);

void initStack(Stack *s, int size){
  s->arr = (int*)malloc(size * sizeof(int));
  s->size = size;
  s->front = 0;
  s->back -1;
  s->cnt = 0;
}

void resize(Stack *s){
  int newSize = s->size * 2;
  int *newArr = (int*)malloc(newSize * sizeof(int));

  for(int i = 0; i < s->size; i++){
    *newArr = *s->arr;
  }
}