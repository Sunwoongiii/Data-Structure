#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE -1
#define TRUE 1

//list 으ㅣ 기본 구성 단위인 node
typedef struct Node {
    int data;
    struct Node* nextNode;
}Node;

typedef struct LinkedList {
    int curCount; //현재 List에 들어있는 node의 개수
    Node headNode; //리스트 시작 노드
}LinkedList;

typedef struct StackNode
{
    int data;
    struct StackNode* next;
}StackNode;


// int addNode(LinkedList* pList, int pos, int data);
// int removeNode(LinkedList* pList, int pos);
// void showNode(LinkedList* pList);
// int isEmpty(LinkedList* pList);
// int findPos(LinkedList* pList, int data);
// void makeEmpty(LinkedList* pList);

void showNode(LinkedList* pList) {
    int i = 0;
    Node* pNode = NULL;

    if(pList == NULL) {
        printf("showNode() error\n");
        return ;
    }
    printf("현재 Node의 개수 : %d\n", pList -> curCount);
    pNode = pList -> headNode.nextNode;
    //pNode가 Linked List의 마지막 노드까지 이동하면서 출력
    while(pNode != NULL) {
        printf("[%d]\n", pNode->data);
        pNode = pNode->nextNode;

    }
    printf("---------------------------------\n");
}
int isEmpty(LinkedList* pList){
    if(pList == NULL) {
        printf("isEmpty() error\n");
        return -1;
    }
    //head node가 가리키는 next node 가 존재하는가?
    if(pList -> headNode.nextNode == NULL) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void makeEmpty(LinkedList* pList) {
    Node* pDummyNode = NULL, *pTmpNode = NULL;
    if(pList != NULL) {
        pTmpNode = pList->headNode.nextNode;
        //연결되어있는 모든 노드들을 탐색
        while (pTmpNode != NULL)
        {
            //Dummy 노드는 지우기 위한 노드
            //Tmp 노드는 이동하기 위한 노드
            pDummyNode = pTmpNode;
            pTmpNode = pTmpNode->nextNode;
            free(pDummyNode);
        }
        pList->headNode.nextNode = NULL;
        
        pList->curCount = 0;

    }
}
int addNode(LinkedList* pList, int pos, int data) {
    int i = 0;
    Node* pNewNode = NULL, *pTmpNode = NULL;
    if(pList == NULL) {
        printf ("addNode() error1\n");
        return FALSE;
    }
    if(pos < 0 || pos > pList->curCount) {
        printf("addNode() error2: 추가범위 초과\n");
        return FALSE;

    }
    pNewNode = (Node*)malloc(sizeof(Node));
    if(!pNewNode){
        printf("addNode error3\n");
        return FALSE;
    }
    pNewNode->data = data;
    pNewNode->nextNode = NULL;
    //추가될 위치 직전 노드로 이동
    pTmpNode = &(pList->headNode);
    for(i = 0; i < pos; i++) {
        pTmpNode = pTmpNode->nextNode;
    }

    //추가노드의 nextNode = 직전노드의 nextNode
    //직전노드의 nextNode = 추가노드의 주소
    pNewNode ->nextNode = pTmpNode -> nextNode;
    pTmpNode -> nextNode = pNewNode;
    pList->curCount++;
    return TRUE;
}

void reversed(LinkedList* pList, StackNode **top) {
    Node* pNode = NULL;
    StackNode* sNode = NULL;
    printf("Reverse Linked List!\n");

    // 연결 리스트의 데이터를 스택에 넣기
    pNode = pList->headNode.nextNode;
    while (pNode != NULL) {
        // 스택에 push
        sNode = (StackNode*)malloc(sizeof(StackNode));
        sNode->data = pNode->data;
        sNode->next = *top;
        *top = sNode;

        pNode = pNode->nextNode;
    }

    // 2️스택에서 꺼내서 리스트에 다시 저장 (순서 바뀜)
    pNode = pList->headNode.nextNode;
    while (*top != NULL && pNode != NULL) {
        pNode->data = (*top)->data;

        // 스택 pop
        sNode = *top;
        *top = (*top)->next;
        free(sNode);

        pNode = pNode->nextNode;
    }
}


int main () {
    int pos;
    LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
    linkedList->curCount = 0;
    linkedList->headNode.nextNode = NULL;

    StackNode* top = NULL;
    StackNode* pNode;

    // showNode(linkedList);
    addNode(linkedList, 0 , 10);
    addNode(linkedList, 5 , 100);
    addNode(linkedList, 1 , 20);
    addNode(linkedList, 2 , 30);
    addNode(linkedList, 1 , 50);
    addNode(linkedList, 1 , 70);
    addNode(linkedList, 1 , 40);

    showNode(linkedList);

    reversed(linkedList, &top);
    showNode(linkedList);

    // pos = findPos(linkedList, 30);
    // printf("the location of node with data '30': %d\n", pos);

    makeEmpty(linkedList); //현재 노드의 개수 다시 확인하기
    showNode(linkedList);
    printf("계속하려면 아무 키나 누르십시오...");
    return 0;

}

