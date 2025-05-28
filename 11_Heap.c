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
*/