#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  int cnt;
  int *arr;
  int front;
  int back;
  int size;
} Stack;

void initStack(Stack *s, int);
void push(Stack *s, int);
void resize(Stack *s);
void pop(Stack *s);
int front(Stack *s);
int back(Stack *s);
bool isEmpty(Stack *s);
int size(Stack *s);
void destroy(Stack *s);

void initStack(Stack *s, int size) {
  s->arr = (int*)malloc(size * sizeof(int));
  if (!s->arr) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  s->size = size;
  s->front = 0;
  s->back = -1;  // 수정
  s->cnt = 0;
}

void resize(Stack *s) {
  int newSize = s->size * 2;
  int *newArr = (int*)malloc(newSize * sizeof(int));
  if (!newArr) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  // 기존 배열 복사
  memcpy(newArr, s->arr, s->size * sizeof(int));

  // 기존 배열 해제 후 교체
  free(s->arr);
  s->arr = newArr;
  s->size = newSize;
}

void push(Stack *s, int val) {
  if (s->size == s->cnt) resize(s);  // 주소 연산자 제거
  s->arr[s->cnt++] = val;
}

int front(Stack *s) {
  if (s->cnt == 0) {
    printf("Stack is Empty\n");
    return -1;
  }
  return s->arr[0];
}

void pop(Stack *s) {
  if (s->cnt == 0) {
    printf("Stack is Empty\n");
    return;
  }
  s->cnt--;  // 단순히 감소 (초기화할 필요 없음)
}

int back(Stack *s) {
  if (s->cnt == 0) {
    printf("Stack is Empty\n");
    return -1;
  }
  return s->arr[s->cnt - 1];  // 감소 연산 없이 올바른 인덱스 반환
}

bool isEmpty(Stack *s) {
  return s->cnt == 0;
}

int size(Stack *s) {
  return s->cnt;
}

void destroy(Stack *s) {
  free(s->arr);
}
