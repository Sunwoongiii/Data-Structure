/*
Strings in C
Representation 
  In C, strings are representeed as character arrays terminated with the null character('\0')
  So, "dog" has 4 memory spaces d,o,g, \0

  char s[] = "dog";
  char u[]; // compile error!
*/

//ex1
// #include <stdio.h>
// #include <stdlib.h> 
// #include <string.h>

// int main(){
//   char s[] = "dog";
//   char t[] = "house";
//   char u[] = "rainbow";
//   printf("%s\n", s);
//   printf("%s\n", t);
//   printf("%s\n\n", u);

//   strcat(s,u);
//   printf("%s\n", s);
//   printf("%s\n", t);
// }

/*
This is an UB
When printing t, the output may be "ainbow"
*/

//ex2 String insertion
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void strnins(char **s, const char *t, int idx){
//   int s_len = strlen(*s);
//   int t_len = strlen(t);
//   int new_len = s_len + t_len;

//   if(idx < 0 || idx > s_len){
//     printf("Position is out of bounds.\n");
//     return;
//   }

//   char *temp = (char *)malloc((new_len + 1) * sizeof(char));
//   if(!temp){
//     printf("Memory allocation failed.\n");
//     return;
//   }

//   strncpy(temp, *s, idx);
//   temp[idx] = '\0';
//   strcat(temp, t);             
//   strcat(temp, *s + idx);      

//   free(*s);
//   *s = temp;
// }

// int main(){
//   int n;

//   printf("Input length of the original word: ");
//   scanf("%d", &n);

//   char *s = (char*)malloc((n + 1) * sizeof(char));
//   if(!s){
//     printf("Memory allocation failed.\n");
//     return 1;
//   }

//   printf("Input original word: ");
//   scanf("%s", s);

//   printf("Input length of the insertion word: ");
//   scanf("%d", &n);
//   char *t = (char*)malloc((n + 1) * sizeof(char));
//   if(!t){
//     printf("Memory allocation failed.\n");
//     free(s);
//     return 1;
//   }

//   printf("Input insertion word: ");
//   scanf("%s", t);

//   int idx;
//   printf("Input index: ");
//   scanf("%d", &idx);

//   strnins(&s, t, idx);

//   printf("Result: %s\n", s);

//   free(s);
//   free(t);

//   return 0;
// }

/*
Pattern Matching
  Does the patters "ello" exist in the string "hello, world" => YES, 1
  Does the pattern "abab" exist in the string "abbabba" =? NO

A library function strstr implements this operation
  t = strstr(string, pat);
  if pat is not in string, a null pointer is returned
  if pat is in the string, a pointer to the start of pat in string is returned
*/

//ex3
// #include <stdio.h>
// #include <string.h>

// int patternMatch(const char *text, const char *pattern){
//   int t_len = strlen(text);
//   int p_len = strlen(pattern);

//   if(p_len > t_len || t_len == 0 || p_len == 0)return -1;

//   for(int i = 0; i <= t_len-p_len; i++){
//     int j;
//     for(j = 0; j < p_len; j++){
//       if(text[i+j] != pattern[j]) break;
//     }
//     if(j == p_len)return i;
//   }
//   return -1;
// }

// void removeNewline(char *str){str[strcspn(str, "\n")] = '\0';}

// int main(){
//   char text[101], pattern[101];

//   printf("Enter the text: ");
//   fgets(text, sizeof(text), stdin);
//   removeNewline(text);

//   printf("Enter the pattern: ");
//   fgets(pattern, sizeof(pattern), stdin);
//   removeNewline(pattern);

//   int index = patternMatch(text, pattern);

//   if(index == -1)printf("Pattern not found\n");
//   else printf("Pattern found at index %d\n", index);

//   return 0;
// }

/*
Time complexcity: O(n*m), n: length of text, m: length of pattern
*/