/*
A sparse matrix is a matirx which contains many zero entries.
objects: set of triple <row, column, value>

We can characterize uniquely any element within a matrix by a triple <row, col, value>
We organize the triples so that row indices are in ascending order and among those with the same row indices are ordered in ascending order of column indices
To ensure that the operations terminates, we must know the number of rows and columns, and the number of non-zero elements in the matrix
*/

//ex1
// typedef struct{
//   int col;
//   int row;
//   int value;
// }Term;

// int main(){
//   Term t[101];
//   t[0].col = 6;
//   t[0].row = 6;
//   t[0].value = 8;//6 by 6 matrix whit 8 non-zero elements
// }

/*
Transpose
  <i,j,value> -> <j,i,value>
  After process maintain the correct order
*/

//ex2 trasposing matirx a to b
// typedef struct{
//   int row;
//   int col;
//   int value;
// }Term;

// void transpose(Term a[], Term b[]){
//   int n,currentb;
//   n = a[0].value; //total number of elements
//   b[0].row = a[0].col;
//   b[0].col = a[0].row;
//   b[0].value = n;

//   if(n > 0){
//     currentb = 1;
//     for(int i = 0; i < a[0].col; i++){
//       for(int j = 0; j < a[0].row; j++){
//         if(a[j].col == i){
//           b[currentb].row = a[j].col;
//           b[currentb].col = a[j].row;
//           b[currentb].value = a[j].value;
//           currentb++;
//         }
//       }
//     }
//   }
// }

/*
Time complexity of function transpose: O(columns * elements)
Worst case: O(rows * columns^2)

A transpose algorithms using dense representation:
for(int j = 0; j < columns; j++)
  for(int i = 0; i < row; i++)
    b[j][i] = a[i][j];

Time complexity: O(row * columns)
*/

//ex3 faseter transpose function
// #define MAX_COL 101
// typedef struct{
//   int row;
//   int col;
//   int value;
// }Term;

// void fast_Transpose(Term a[], Term b[]){
//   int row_terms[MAX_COL], starting_pos[MAX_COL];
//   int num_cols = a[0].col, num_terms = a[0].value;
//   b[0].row = num_cols;
//   b[0].col = a[0].row;
//   b[0].value = num_terms;

//   if(num_terms > 0){
//     for(int i = 0; i < num_cols; i++)row_terms[i] = 0;
//     for(int i = 1; i <= num_terms; i++)row_terms[a[i].col]++;
//     starting_pos[0] = 1;
//     for(int i = 1; i < num_cols; i++) starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
//     for(int i = 1; i <= num_terms; i++){
//       int j = starting_pos[a[i].col]++;
//       b[j].row = a[i].col;
//       b[j].col = a[i].row;
//       b[j].value = a[i].value;
//     }
//   }
// }

/*
Time complexcity: O(columns + elements)
Worst case: O(columns * rows)
*/