/*
Heap

Max Tree: a tree in which the key value in each node is no smaller than the key values in its children
Max Heap: complete BT that is also a max tree

Min Tree: a tree in which the key value in each node is no larger than the key values in its children
Min Heap: a complete BT that is also a min tree

ADT MaxHeap
object: complete BT organized so that the value in each node is at least as large as those in its children
function:
  MaxHeap Create(max_size): create an empty heap
  Boolean HeapFull: if(n == max_size)return TRUE
  MaxHeap Insert(heap, item, n): insert an item into heap and return the resulting heap
  MaxHeap Delete(heap, n) return one of the largest element in the heap and remove it from the heap

Heaps are frequently used to implement Priority Queues
Priority Queue deletes the element with the highest/lowest priority key

Implementing PQ
- Unordered array, unordered linked list
- Sorted array, sorted linked list
- Heap
  Elements are maintained in a heap structure
  When inserting/deleting, the heap is reorganized in order to maintain its characteristics
*/

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX_ELEMENT 200
// #define HEAP_FULL(n) (n==MAX_ELEMENT-1)
// #define HEAP_EMPTY(n) (!n)
// typedef struct{
//   int key;
// }element;

// element heap[MAX_ELEMENT];
// int n = 0;

// void insert_max_heap(element item, int* n){
//   //insert item into a max heap of current size * n
//   int i;
//   if(HEAP_FULL(*n)){
//     fprintf(stderr, "Heap is full.\n");
//     exit(1);
//   }
//   i = ++(*n);
//   while((i != 1) && (item.key > heap[i/2].key)){
//     heap[i] = heap[i/2];
//     i /= 2;
//   }
//   heap[i] = item;
// }

// element delete_max_heap(int *n){
//   //delete element with the highest key from the heap
//   int parent, child;
//   element item, temp;
//   if(HEAP_EMPTY(*n)){
//     fprintf(stderr, "Heap is empty.\n");
//     exit(1);
//   }
//   //save value of the element with the largest key
//   item = heap[1];
//   temp = heap[(*n)--];
//   parent = 1;
//   child = 2;
//   while(child <= 2){
//     //find the larger child of the current parent
//     if((child < *n) && (heap[child].key < heap[child+1].key))child++;
//     if(temp.key >= heap[child].key)break;
//     //move to the next lower level
//     heap[parent] = heap[child];
//     parent = child;
//     child *= 2;
//   }
//   heap[parent] = temp;
//   return item;
// }