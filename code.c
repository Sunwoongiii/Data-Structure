#include <stdio.h>

void print1(int *ptr, int rows){
  printf("Address Contents\n");

  for(int i =0; i < rows; i++){
    printf("%8u%5d\n", ptr+i, *(ptr+i));
    printf("\n");
  }
}

int main(){
  int arr[5];
  for(int i = 0; i < 5; i++)arr[i] = i * 2;

  print1(arr, 5);
}