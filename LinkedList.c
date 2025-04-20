#include <stdio.h>
#include <stdlib.h> 

struct Node{
  int data;
  struct Node *next;
};

typedef struct Node *PtrToNode; //간선
typedef PtrToNode List; //첫번째 이전 더미 노드드
typedef PtrToNode Position; //특정 노드

List MakeEmpty(List L){
  L = NULL;
  return L;
}

int isEmpty(List L){
  return L->next == NULL;
}

int IsLast(Position P, List L){
  return (P->next == NULL);
}

Position Find(int x, List L){
  Position p;

  p = L->next;
  while(p != NULL && p->data != x) p = p->next;

  return p;
}

void delete(int x, List L){
  Position p, tmp;
  p = findPrevious(x,L);
  if(!isLast(p,L)){
    tmp = p->next;
    p->next = tmp->next;
    free(tmp);
  }
}

Position findPrevious(int x, List L){
  Position p;
  p = L;
  while(p->next != NULL && p->next->data != x) p = p->next;

  return p;
}

void insert(int x, List L, Position p){
  Position tmp;
  tmp = malloc(sizeof(struct Node));

  if(tmp == NULL){
    fprintf(stderr, "Fatal error");
    exit(0);
  }

  tmp->data = x;
  tmp->next = p->next;
  p->next = tmp;
}