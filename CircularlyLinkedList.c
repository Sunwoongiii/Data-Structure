#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

typedef Node* Position;
typedef Position List;

// 초기화: dummy head node를 만들어서 자기 자신을 가리키도록 함
List init() {
  List head = malloc(sizeof(Node));
  if (head == NULL) {
    fprintf(stderr, "Out of memory!\n");
    exit(1);
  }
  head->next = head;
  head->prev = head;
  return head;
}

// 삽입: p 다음에 새로운 노드를 삽입
void insert(int x, Position p) {
  Position tmp = malloc(sizeof(Node));
  if (tmp == NULL) {
    fprintf(stderr, "Out of memory!\n");
    exit(1);
  }

  tmp->data = x;
  tmp->next = p->next;
  tmp->prev = p;
  p->next->prev = tmp;
  p->next = tmp;
}

// 검색: x 값을 가진 노드 찾기
Position find(int x, List L) {
  Position p = L->next;
  while (p != L && p->data != x)
    p = p->next;

  return (p == L) ? NULL : p;  // 못 찾았으면 NULL
}

// 삭제: x 값을 가진 노드 삭제
void delete(int x, List L) {
  Position p = find(x, L);
  if (p == NULL) return; // 못 찾은 경우
  
  p->prev->next = p->next;
  p->next->prev = p->prev;
  free(p);
}
