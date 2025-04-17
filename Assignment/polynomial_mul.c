#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#define BUFFSIZE 1024

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct polyTerm{
  int order;
  int coeff;
  struct polyTerm* nextNode;
} polyTerm;

typedef struct poly{
  polyTerm headNode;
} poly;

void clearPoly(poly* A){
  polyTerm* curr = A->headNode.nextNode;

  while (curr != NULL){
    polyTerm* temp = curr;
    curr = curr->nextNode;
    free(temp);
  }

  A->headNode.nextNode = NULL;
}

void addTerm(poly* A, int exp, int coeff){
  if (coeff == 0)return;

  polyTerm* prev = &A->headNode;
  polyTerm* curr = A->headNode.nextNode;

  while (curr != NULL && curr->order > exp){
    prev = curr;
    curr = curr->nextNode;
  }

  if (curr != NULL && curr->order == exp){
    curr->coeff += coeff;

    if (curr->coeff == 0){
      prev->nextNode = curr->nextNode;
      free(curr);
    }
  }else{
    polyTerm* newTerm = (polyTerm*)malloc(sizeof(polyTerm));
    newTerm->order = exp;
    newTerm->coeff = coeff;
    newTerm->nextNode = curr;
    prev->nextNode = newTerm;
  }
}

poly multiPoly(poly A, poly B){
  poly result;
  result.headNode.nextNode = NULL;

  polyTerm* termA = A.headNode.nextNode;
  while(termA != NULL){
    polyTerm* termB = B.headNode.nextNode;
    while(termB != NULL){
      int newCoeff = termA->coeff * termB->coeff;
      int newOrder = termA->order + termB->order;

      addTerm(&result, newOrder, newCoeff);
      termB = termB->nextNode;
    }
    termA = termA->nextNode;
  }

  return result;
}

void printPoly_impl(poly A, char* buffer){
  char temp[BUFFSIZE];
  polyTerm* curr = A.headNode.nextNode;
  int first = 1;

  while(curr != NULL){
    if(curr->coeff == 0){
      curr = curr->nextNode;
      continue;
    }

    if (first != 1) {
      if (curr->coeff > 0) strcat(buffer, "+");
      else strcat(buffer, "-");
    }else{
      if (curr->coeff < 0) strcat(buffer, "-");
      first = 0;
    }

    int absCoeff;
    if(curr->coeff < 0) absCoeff = -curr->coeff;
		else absCoeff = curr->coeff;

    sprintf(temp, "%d", absCoeff);

    char expStr[20];
    sprintf(expStr, "x^%d", curr->order);
    strcat(temp, expStr);

    strcat(buffer, temp);
    curr = curr->nextNode;
  }

  if(first){
    strcat(buffer, "0");
  }
}

void printPoly(poly A){
  char buffer[BUFFSIZE] = "";

  printPoly_impl(A, buffer);
  printf("%s", buffer);
}

int main(){
  poly A, B;
  A.headNode.nextNode = NULL;
  B.headNode.nextNode = NULL;

  addTerm(&A, 1, 1);
  addTerm(&A, 0, 1);
  printf("poly A: ");
  printPoly(A);
  printf("\n");

  addTerm(&B, 1, 1);
  addTerm(&B, 0, -1);
  printf("poly B: ");
  printPoly(B);
  printf("\n");

  printf("A*B: ");
  printPoly(multiPoly(A, B));
  clearPoly(&A);
  clearPoly(&B);
  return 0;
}