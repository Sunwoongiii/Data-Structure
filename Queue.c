#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Queue {
  int *arr;
  int front;
  int back;
  int size;
  int cnt;
};

void initQueue(struct Queue *q, int size) {
  q->arr = (int *)malloc(size * sizeof(int));
  q->front = 0;
  q->back = -1;
  q->size = size;
  q->cnt = 0;
}

void resize(struct Queue* q) {
  int newSize = q->size * 2;
  int *newArr = (int*)malloc(sizeof(int) * newSize);

  for (int i = 0; i < q->cnt; i++) {
    newArr[i] = q->arr[(q->front + i) % q->size];
  }
  free(q->arr);

  q->arr = newArr;
  q->size = newSize;
  q->front = 0;
  q->back = q->cnt - 1;
}

void push(struct Queue* q, int val) {
  if (q->cnt == q->size) resize(q);
  q->back = (q->back + 1) % q->size;
  q->arr[q->back] = val;
  q->cnt++;
}

int pop(struct Queue* q) {
  if (q->cnt == 0) return -1;
  else {
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->size;
    q->cnt--;
    return val;
  }
}

bool isEmpty(struct Queue *q) {
  return q->cnt == 0;
}

int size(struct Queue* q) {
  return q->cnt;
}

int front(struct Queue* q) {
  if (q->cnt == 0) return -1;
  return q->arr[q->front];
}

int back(struct Queue* q) {
  if (q->cnt == 0) return -1;
  return q->arr[q->back];
}

void destroyQueue(struct Queue* q) {
  free(q->arr);
}

int main() {
  int T;
  scanf("%d", &T);
  struct Queue q;
  initQueue(&q, 10);

  while (T--) {
    char command[10];
    int val;

    scanf("%s", command);

    if (strcmp(command, "push") == 0) {
      scanf("%d", &val);
      push(&q, val);
    }
    else if (strcmp(command, "pop") == 0) {
      int ans = pop(&q);
      printf("%d\n", ans);
    }
    else if (strcmp(command, "size") == 0) {
      int ans = size(&q);
      printf("%d\n", ans);
    }
    else if (strcmp(command, "empty") == 0) {
      bool flag = isEmpty(&q);
      if (flag) printf("1\n");
      else printf("0\n");
    }
    else if (strcmp(command, "front") == 0) {
      int ans = front(&q);
      printf("%d\n", ans);
    }
    else {
      int ans = back(&q);
      printf("%d\n", ans);
    }
  }

  destroyQueue(&q);
  return 0;
}
