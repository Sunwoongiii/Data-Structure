/*
Array
A set of pairs : <index, value>, such that each index has a value associated with it.
ex)
  <0, 99>, <1, 88>, <2, 77>...
  <0, 'a'>, <1, 'b'>, <2, 'c'>
  int list[5];
  list[0] = base address = a;
  list[1] = a + sizeof(int);
  list[2] = a + 2*sizeof(int);
  ...
  list is continuous(linear)

  int list2[5];
  "list2" is interpreted as a pointer to an integer
  list2[0] : int
  list2 : int*
  list2 + i = a pointer to list2[i]
  list2+i == &list2[i]
  *(list2+i) == list2[i]

  !do not think a indexing as a byte!
  list2 + 4 != list[1]
*/

//ex1
// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//   int i;
//   int list[5];

//   for(int i = 0; i < 5; i++)list[i] = i+101;
//   printf("%p: %d\n", list, *list);
//   printf("%p: %d\n", &list[0], list[0]);
//   printf("%p: %d\n", (list+1), *(list+1));
//   printf("%p: %d\n", &list[1], list[1]);  //the difference between the address of the list is 4
// }

//ex2
// #include <stdio.h>
// #define MAX 100

// float sum(float[], int);
// float input[MAX], answer;
// int i;

// int main(){
//   for(i = 0; i < MAX; i++)input[i] = i;
//   answer = sum(input, MAX);
//   printf("%f", answer);
// }

// float sum(float list[], int n){
//   int i;
//   float temp = 0;
//   for(int i = 0; i < MAX; i++){
//     temp += list[i];
//   }
//   return temp;
// }

//ex3
// #include <stdio.h>

// void print1(int*, int);
// int main(){
//   int one[] = {0,1,2,3,4};
//   print1(one, 5);
// }

// void print1(int *ptr, int size){
//   int i;
//   printf("Address contents\n");
//   for(int i = 0; i < size; i++)printf("%8p%5d\n", ptr+i, *(ptr+i));
// }

/*
from ex1 ~ ex3 is a [Static Array]
[Static Array]
  Fixed size: the size of the array is determined at compile time and cannot be changed during runtime
  Contiguous Memory Allocation: memory is allocated in contiguous blocks, enabling fast access and indexing
  ex)
    int arr[10]; //Static Array with a fixed size of 10

[Dynamic Array]
  Resizable: the size can be adjusted during runtime as needed
  Memory Reallocation: when more space is required, new memory blocks are allocated, and existing data is copied
  ex)
    int *arr = (int *)malloc(10 * sizeof(int)); //Dynamic Array with initial size 10
    arr = (int *)realloc(arr, 20 * sizeof(int)); // Resize to 20
*/

//ex4: malloc
// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//   int i,n, *data;
//   printf("How many integers do you want to generate: ");
//   scanf("%d", &n);

//   data = malloc(n * sizeof(int));
//   for(int i = 0; i < n; i++){
//     data[i] = rand();
//     printf("%d\n", data[i]);
//   }
//   free(data);
//   return 0;
// }

/*
once you used your DA, you SHOULD free() the data
*/

//ex5: realloc
// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//   int i,n,m,*data;
//   printf("How many integers do you want to generate?: ");
//   scanf("%d", &n);
//   data = malloc(n * sizeof(int));
//   printf("memory allocated at %p\n", data);

//   for(i = 0; i < n; i++) data[i] = rand();

//   printf("How many integer do you want to generate additionally?: ");
//   scanf("%d", &m);
//   data = realloc(data, (n+m) *sizeof(int));
//   printf("memory reallocated at %p\n", data);
  
//   for(i = 0; i < n + m; i++)data[i] = rand();

//   for(i = 0; i < n+m; i++)printf("%d\n", data[i]);
//   free(data);
//   return 0;
// }

/*
the memory address can differ once we reallocate the data
*/

//ex6: Two Dimension
// #include <stdio.h>
// #include <stdlib.h>

// int** make2dArray(int, int);

// int main(){
//   int i,j;
//   int **matrix;

//   matrix = make2dArray(5,5);
//   for(int i = 0; i < 5; i++){
//     for(int j = 0; j < 5; j++){
//       matrix[i][j] = i * 5 + j + 1;
//       printf("%2d ", matrix[i][j]);
//     }
//     printf("\n");
//   }

//   for(int i = 0; i < 5; i++) free(matrix[i]);
//   free(matrix);
//   return 0;
// }

// int** make2dArray(int rows, int cols){
//   int **x, i;
//   x = malloc(rows * sizeof(*x));
  
//   for(i = 0; i < rows; i++){
//     x[i] = malloc(cols * sizeof(**x));
//   }
//   return x;
// }

/*
2-D array: double pointer, points to an array of <type>* (<type> pointer), after memory allocation, it stores the address of the first row.
2-D array[index]: <type> pointer, points to the columns in the first row.
2-D arr[intdex][index]: <type> value
*/