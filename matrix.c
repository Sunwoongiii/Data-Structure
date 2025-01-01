#include <stdio.h>

void mulMatrix(int reuslt[][5], int matrix[][5], int n){
  int temp[5][5] = {0,};
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++)temp[i][j] += (reuslt[i][k] * matrix[k][j]) % 1000;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)reuslt[i][j] = temp[i][j] % 1000;
  }
}

int main(){
  int N;
  long long B;

  scanf("%d %lld", &N, &B);
  int matrix[5][5];
  int result[5][5] = {0,};

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%d", &matrix[i][j]);
      result[i][i] = 1;
    }
  }

  while(B){
    if(B%2)mulMatrix(result, matrix, N);
    mulMatrix(matrix, matrix, N);
    B /= 2;
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}