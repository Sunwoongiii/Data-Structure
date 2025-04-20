#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};

typedef struct Node *ptrToNode;
typedef ptrToNode List; //첫번째 이전 더미 노드드
typedef ptrToNode Position;

int isEmpty(List L){
  return L->data == NULL;
}

int isLast(Position p, List L){
  return p->next == NULL;
}

Position find(int x, List L){
  Position p = L->next;
  while(p != NULL && p->data != x){
    p = p->next;
  }
  return p;
}

void delete(int x, List L){
  Position tmp = find(x,L);

  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  free(tmp);
}

void insert(int x, List L, Position p) {
  Position tmp;
  tmp = malloc(sizeof(struct Node));

  if (tmp == NULL) {
    fprintf(stderr, "Fatal error\n");
    exit(1);
  }

  tmp->data = x;
  tmp->next = p->next;
  tmp->prev = p;

  // 만약 p가 마지막 노드가 아니라면, 새 노드를 그 다음 노드와 연결
  if (p->next != NULL) {
    p->next->prev = tmp;
  }

  p->next = tmp;
}
