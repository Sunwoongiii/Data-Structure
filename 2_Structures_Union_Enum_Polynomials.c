/*
structure: collection of data items, where each item is identified by its type and name
we can use a dot operator(.) to access a particular member variable
*/

//ex1: without "typedef"
// struct Person{
//   char name[20];
//   int age;
//   float salary;
// };

// int main(){
//   struct Person p1;
//   p1.age = 21;
//   strcpy(p1.name, "SunWoong");
//   p1.salary = 60.000000;
// }

//ex2: with "typedef"
// typedef struct{
//   char name[20];
//   int age;
//   float salary;
// } Person;

// int main(){
//   Person p1;
//   p1.age = 21;
//   strcpy(p1.name, "SunWoong");
//   p1.salary = 60.000000;
// }
/*
without "typedef"
  Declaration: struct Person p1;
  Keyword Required: always requires "struct" keyword
  Readability: Longer and less readable
  Flexibility: More explicit

with "typedef"
  Declaration: Person p1;
  Keyword Required: No "struct" keyword needed
  Readability: Shorter and cleaner syntax
  Flexibility: Easier for defining aliases
*/

//ex3: struct as a member variable
// typedef struct{
//   int month;
//   int day;
//   int year;
// }Date;

// typedef struct{
//   char name[20];
//   int age;
//   float salary;
//   Date today;
// }Person;

// int main(){
//   Person p1;
//   p1.age = 21;
//   strcpy(p1.name, "SunWoong");
//   p1.salary = 60.000000;

//   p1.today.day = 27;
//   p1.today.month = 12;
//   p1.today.year = 2024;
// }

/*
Unions: fiels that share memory space, only one field of union is active at any given time, which means we can ONLY choose one of the value, allocates memory with the largest memory type
*/

//ex4: using Union
// union Data{
//   int i;
//   float f;
//   char str[20];
// };

// int main(){
//   union Data data;
//   data.i = 10;
//   data.f = 220.5;
//   strcpy(data.str, "Hello");
// }

// ex5: using Union with typedef
// typedef union{
//   int i;
//   float f;
//   char str[20];
// }Data;

// int main(){
//   Data data;
//   data.i = 10;
//   data.f = 220.5;
//   strcpy(data.str, "Hello");
// }

/*
Enum: a data type used to define a set of named constant values, it is used to represent relatede values and is automatically maped to integers
Features:
  Improved Code Readability: constants are defined with meaningful names, making the code easier to understand.
  Automatic Value Assignment: The first value is assigned as 0, and subsequent values increase by 1.
  Custom Value Assignment: specific values cna be assigned explicitly.
*/

//ex6: using enum(we can use "typedef")
// enum Color{
//   RED,
//   GREEN,
//   BLUE
// };

// enum WeekDay{
//   MON = 1,
//   TUE,
//   WED,
//   THU = 10,
//   FRI
// };

// int main(){
//   enum Color myColor = GREEN;
//   enum WeekDay day =FRI;
// }

//ex7: using Union and enum
// typedef struct{
//   enum tagField {pitcher, hitter} role;
//   union{
//     int SO;
//     int HR;
//   }u;
// }PlayerType;

// typedef struct{
//   char name[20];
//   int age;
//   float salary;
//   PlayerType playerInfo;
// }BaseballPlayer;

// int main(){
//   BaseballPlayer p1, p2;
//   p1.playerInfo.role = pitcher;
//   p1.playerInfo.u.SO = 163;

//   p2.playerInfo.role = hitter;
//   p2.playerInfo.u.HR = 24;
// }

//ex8: Self-Referential Structures
// #include <stdlib.h>

// typedef struct{
//   char data;
//   List *link;
// }List;

// int main(){
//   List item1, item2, item3;

//   item1.data = 'a';
//   item2.data = 'b';
//   item3.data = 'c';

//   item1.link = item2.link = item3.link = NULL;

//   item1.link = &item2;
//   item2.link = &item3;
// }

//the Self-Referential Structures are used in Linked List

/*
Polynomials
  A(x) = 3x^2 + 2x + 4
  in a * x^e
  x: variable
  a: coefficient
  e: exponent

  we can represent the x,a,e as a set of ordered pairs <a_i,e_i>

There are many ways to represent a polynomial
  dense representation
  sparse representation
*/

/*
Dense Representation
  include all terms in a polynomial, including terms that have zero coefficient\
  A(x) = a_n * x^n + ...
  a.degree == n;
  a.coef[i] == a_i;

Advantage
  operations can be implemented ia a simple manner(ex adding two polynomials)

Problem
  may waste a lot of memory space if
    a.degree is much smaller than MAX_DEGREE
    polynomial is sparse(most terms have zeor coefficients)
*/

//ex9: Dense Representation
// #define MAX_DEGREE 101
// typedef struct{
//   int degree;
//   int coef[MAX_DEGREE];
// }Polynomial;

// int main(){
//   Polynomial a;
//   //a(x) = 2x^3 + 3x^2 + 4
//   a.degree = 3;
//   a.coef[0] = 4;
//   a.coef[1] = 0;
//   a.coef[2] = 3;
//   a.coef[3] = 2;

//   // a.coef[0] = 2;
//   // a.coef[1] = 3;
//   // a.coef[2] = 0;
//   // a.coef[3] = 4;
// }

/*
Sparse Representation
  each term of a polynomial includes exponet AND coefficient
  does not need to store terms that have zeor coefficient.

Advantage
  saves memory space

Problem
  operations become complex
*/

//ex10: Sparse Representation
/*
#define MAX_TERMS 100
typedef struct{
  int coef;
  int expon;
}Polynomial;

Polynomial terms[MAX_TERMS];
int avail = 0;

A(x) = 2x^1000 + 1
B(x) = x^4 + 10x^3 + 3x^2 + 1

term 2     1  1  10  3  1
coe  1000  0  4  3   2  0 
idx 0      1  2  3   4  5

startA = 0
finishA = 1
startB = 2
finishB = 5
avail = 6
*/