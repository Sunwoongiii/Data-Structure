#include <stdio.h>
#include <stdlib.h>
#define FALSE -1
#define TRUE 1

typedef struct Node{
  int data;
  struct Node *next;
}Node;

typedef struct LinkedList{
  int cnt;
  Node headNode;
}LinkedList;

typedef struct StackNode{
  int data;
  struct StackNode *next;
}StackNode;

int isEmpty(LinkedList* pl){
  if(pl==NULL){
    fprintf(stderr,"isEmpty() error\n");
    exit(1);
  }
  if(pl->headNode.next==NULL){
    return TRUE;
  }
  else return FALSE;
}

void makeEmpty(LinkedList *pl){
  Node *pHead=NULL,*pTmp=NULL;
  if(pl!=NULL){
    pTmp=pl->headNode.next;
    while(pTmp!=NULL){
      pHead=pTmp;
      pTmp=pTmp->next;
      free(pHead);
    }
    pl->headNode.next=NULL;
    pl->cnt=0;
  }
}

int addNode(LinkedList *pl,int pos,int data){
  Node *pNewNode=NULL,*pTmp=NULL;
  if(pl==NULL){
    fprintf(stderr,"addNode() error1\n");
    return FALSE;
  }
  if(pos<0||pos>pl->cnt){
    fprintf(stderr,"addNode() error2: 추가범위 초과\n");
    return FALSE;
  }
  pNewNode=(Node*)malloc(sizeof(Node));
  if(!pNewNode){
    fprintf(stderr,"addNode() error3: 메모리 할당 실패\n");
    return FALSE;
  }
  pNewNode->data=data;
  pNewNode->next=NULL;

  pTmp=&(pl->headNode);
  for(int i=0;i<pos;i++){
    pTmp=pTmp->next;
  }
  pNewNode->next=pTmp->next;
  pTmp->next=pNewNode;
  pl->cnt++;
  return TRUE;
}

void reverse(LinkedList *pl,StackNode **top){
  Node *pNode=NULL;
  StackNode *sNode=NULL;
  printf("Reverse Linked List\n");

  pNode=pl->headNode.next;
  while(pNode!=NULL){
    sNode=(StackNode*)malloc(sizeof(StackNode));
    sNode->data=pNode->data;
    sNode->next=*top;
    *top=sNode;
    pNode=pNode->next;
  }

  pNode=pl->headNode.next;
  while(*top!=NULL&&pNode!=NULL){
    pNode->data=(*top)->data;

    sNode=*top;
    *top=(*top)->next;
    free(sNode);

    pNode=pNode->next;
  }
}

void showNode(LinkedList *pl){
  Node *pNode=NULL;
  if(pl==NULL){
    fprintf(stderr,"showNode() error\n");
    exit(1);
  }
  printf("현재 Node의 개수: %d\n",pl->cnt);
  pNode=pl->headNode.next;
  while(pNode!=NULL){
    printf("[%d]\n",pNode->data);
    pNode=pNode->next;
  }
  printf("---------------------------------\n");
}

int main(){
  int pos;
  LinkedList *linkedList=(LinkedList*)malloc(sizeof(LinkedList));
  linkedList->cnt=0;
  linkedList->headNode.next=NULL;
  linkedList->headNode.data=0;

  StackNode *top=NULL;

  addNode(linkedList,0,10);
  addNode(linkedList,5,100);
  addNode(linkedList,1,20);
  addNode(linkedList,2,30);
  addNode(linkedList,1,50);
  addNode(linkedList,1,70);
  addNode(linkedList,1,40);

  showNode(linkedList);

  reverse(linkedList,&top);
  showNode(linkedList);

  makeEmpty(linkedList);
  showNode(linkedList);

  printf("계속하려면 아무 키나 누르십시오...");
  return 0;
}
