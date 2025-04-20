#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

typedef struct Node *ptrToNode;
typedef ptrToNode Stack;

void fatalError(const char *msg){
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

int IsEmpty(Stack S){
  return S->next == NULL;
}

Stack createStack(){
  Stack S = malloc(sizeof(struct Node));
  if(S == NULL){
    fatalError("Out of Space");
  }

  S->next = NULL;
  return S;
}

void Push(int x, Stack S){
  ptrToNode tmp = malloc(sizeof(struct Node));
  if(tmp == NULL) fatalError("Out of space");

  tmp->data = x;
  tmp->next = S->next;
  S->next = tmp;
}

void Pop(Stack S){
  if(IsEmpty(S))fatalError("Empty Stack");

  ptrToNode head = S->next;
  S->next = head->next;
  free(head);
}

int Top(Stack S){
  if(IsEmpty(S))fatalError("Empty Stack");
  return S->next->data;
}