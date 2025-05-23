#include <stdio.h>

int move_cnt=0;

void hanoi(int n, char from, char middle, char to){
  if(n == 1){
    printf("%d번 원판을 %c에서 %c로 이동\n", n, from, to);
    move_cnt++;
    return;
  }

  hanoi(n-1, from, to, middle);
  printf("%d번 원판을 %c에서 %c로 이동\n", n, from, to);
  move_cnt++;
  hanoi(n-1, middle, from, to);
}

int main(){
  int n;
  printf("원판의 개수를 입력하세요: ");
  scanf("%d", &n);

  hanoi(n, 'A', 'B', 'C');
  printf("총 이동 횟수: %d", move_cnt);

  return 0;
}