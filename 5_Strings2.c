/*
KMP(Knuth-Morris-Patt) Algorithm
  A better algorithm for finding a pattern in a string.

  Idea: When a mismatch occurs, use our knowledge of the characters in the pattern and the position in the pattern when the mismatch occured, to determine where we should continue the search.

  We want to search the string for the pattern without moving backwards in the string.
*/

//ex
#include <stdio.h>
#define MAX 1000000

int skip[MAX];

int mstrlen(char* str){
  int n = -1;
  while(str[++n]);
  return n;
}

void make_skip_table(char* str, int len){
  for(int i = 0; i < MAX; i++) skip[i] = 0;
  
  int j = 0;
  for(int i = 1; i < len; i++){
    while(j > 0 && str[i] != str[j]){
      j = skip[j-1];
    }

    if(str[i] == str[j]){
      skip[i] = ++j;
    }
  }
}

int do_kmp(int N, char *text, int M, char *pattern){
  make_skip_table(pattern, M);

  int cnt = 0, j = 0;

  for(int i = 0; i < N; i++){
    while(j > 0 && text[i] != pattern[j]){
      j = skip[j-1];
    }

    if(text[i] == pattern[j]){
      if(j == M-1){
        printf("found: %d\n", i+1);
        cnt++;
        j = skip[j];
      }
      else{
        j++;
      }
    }
  }
  return cnt;
}

int main(){
  char a[] = "tomatitomatotomato";
  char b[] = "tomato";

  int found = do_kmp(mstrlen(a), a, mstrlen(b),b);
  printf("found count: %d\n", found);
  return 0;
}