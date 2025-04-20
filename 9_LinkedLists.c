/*
Sequential representation
  sorting successive elements of the data object a fixed distance apart
  
  adequate for many operations
    sequentially inserting elements
    reading elements sequentially or arbitrarily

  difficulty occurs when
    inserting or deleting an arbitrarily element
    storing several list of varing sizes in different arrays of maximum size
    data movements are frequent


Linked representation
  A node, associated with an element in the list, contains a data component and a pointer to the next item in the list
  the pointers are often called links

Review: Pointers
  int i;
  int *pi;

  pi = & i; // the value of pi is the memory address of i
  i = 10;
  *pi = 10; // same as assigning 10 to variable i

  The NULL pointer
    The NULL pointer points to NOTHING (no object nor function)
    The NULL pointer is represented by integer 0
      if a pointer type variable has value 0, it is a NULL pointer
      NULL is defined to be 0 in <stdio.h>

    int *pi = NULL;
    *pi = 100; // cannot assign a value to a NULL pointer
  
  Care must be taken when using pointers
  int i,j,*pi,*pj;
  pi = &i; pj = &j;
  *pi = 100; *pj = 200;
  *(pi + 1) = 300; // what is "pi+1" => not defined

Linked Lists
  Each element maintains a pointer(a link) to the next element
  The last element "e" points to NULL
  There is a pointer variable "first" that points to the first element

  1. Singly Linked List
    A basic type of linked lists
    Also called chains

  2. Circular List
    The last element points to the first element

  3. Doubly Linked List
    Each node points to the next node and the previous node
  
  4. Doubly Linked Circular List
    Each node points to the next node ant the previous node
    The next node of the last node is the first node
    The previous node of the first node is the last node

Representation
#include <stdio.h>

struct listNode{
  char data;
  struct listNode *link;
};

struct listNode *first;

Reading the first element(has 5 element)
struct listNode *currNode = first;
return currNode->data;

Reading the second element(has 5 element)
currNode = first->link;
return currNode->data;

Reading the third element(has 5 element)
currNode = first->link->link;
return currNode->data;

Deleting an Element
  Deleting the first element
    struct ListNode *delNode = first;
    first = first->link; // move the "first" pointer
    free(delNode);
  
  Deleting an element from the middle of the list
    struct listNode *beforeNode, *delNode
    delNode = beforeNode->link;
    beforeNod->link = beforeNode->link->link; //when deleting third node
    free(beforeNode);

  Inserting an Element
    newNode->link = first;
    first = newNode;
*/
#include <stdio.h>
#include <stdlib.h>

struct listNode{
  char data;
  struct listNode *link;
};

struct listNode *first = NULL;

int main(){
  struct listNode *newNode, *prevNode = NULL;
  struct listNode *currNode;
  char c;

  for(c = 'a'; c <= 'e'; c++){
    newNode = malloc(sizeof(*newNode));
    newNode->data = c;
    newNode->link = NULL;

    if(prevNode == NULL)first = newNode;
    else prevNode->link = newNode;
    prevNode = newNode;
  }

  //print all elements in the list
  currNode = first;
  while(currNode){
    printf("%c\n", currNode->data);
    currNode = currNode->link;
  }

  //reading the third element from the list
  currNode = first->link->link;
  printf("reading the 3rd element: %c\n", currNode->data);

  //deleting the third element from the list
  prevNode = first->link;
  currNode = prevNode->link;
  prevNode->link = prevNode->link->link;
  printf("deleting the 3rd element\n");
  free(currNode);

  //inserting a new element 'f' as the third element in the list
  newNode = malloc(sizeof(*newNode));
  newNode->data = 'f';
  newNode->link = NULL;
  prevNode = first->link;
  newNode->link = prevNode->link;
  prevNode->link = newNode;
  printf("inserting 'f' as the 3rd element\n");
}