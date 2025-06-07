/*
Consider a weighted undirected graph that is connected

Minimum Spanning Tree: A spanning tree that has the least cost
- Kruskal's Algorithm
- Prim's Algorithm
=> Greedy Algorithm

Kruskal's Algorithm 
- Builds a minimum cost spanning tree T by adding edges to T one at a time. 
- Selects the edges for inclusion in T in nondecreasing order of their cost. 
- An edge is added to T if it does not form a cycle with edges that are already in T.
- If G is connected and has vertices n > 0, exactly n-1 edges will be selected for inclusion in T.

Pseudocode
T = {};
while(T contains less than n-1 edges && E is not empty){
  choose a least cost edges (v,w) from E;
  delete (v,w) from E;
  if((v,w) does not create a cycle in T) add(v,w) to T;
  else discard(v,w);  
}
if(T contains fewer than n-1 edges) printf("No spanning Tree\n");

Implementing Kruskal's Algorithms
- Selecting an edge in E and not in T that has the minimum cost
  Use a min heap 
- Checking whether adding an edge in T will create a cycle
  Suppose the edge we select next is (u,w). Then, we should find out whether u ans w is already connected in T.
  use disjoint sets and union-find
*/
// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 101

// typedef struct Edge{
//   int src, dest, weight;
// }Edge;

// typedef struct Graph{
//   int V, E;
//   Edge edges[MAX];
// }Graph;

// typedef struct subset{
//   int parent, rank;
// }subset;

// typedef struct MinHeap{
//   int size;
//   Edge* array;
// }MinHeap;

// MinHeap* createMinHeap(int capacity){
//   MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
//   heap->size = 0;
//   heap->array = (Edge*)malloc(sizeof(MinHeap));
//   return heap;
// }

// void minHeapify(MinHeap* heap, int idx){
//   int smallest = idx;
//   int left = 2 * idx + 1;
//   int right = 2 * idx +2;

//   if(left < heap->size && heap->array[left].weight < heap->array[smallest].weight) smallest = left;
//   if(right < heap->size && heap->array[right].weight < heap->array[smallest].weight) smallest = right;
//   if(smallest != idx){
//     Edge temp = heap->array[idx];
//     heap->array[idx] = heap->array[smallest];
//     heap->array[smallest] = temp;
//     minHeapify(heap, smallest);
//   }
// }

// Edge extractmin(MinHeap* heap){
//   Edge min = heap->array[0];
//   heap->array[0] = heap->array[heap->size-1];
//   heap->size--;
//   minHeapify(heap, 0);
//   return min;
// }

// void insertEdge(MinHeap* heap, Edge edge){
//   heap->size++;
//   int i = heap->size-1;
//   while(i > 0 && edge.weight < heap->array[(i-1)/2].weight){
//     heap->array[i] = heap->array[(i-1)/2];
//     i = (i-1)/2;
//   }
//   heap->array[i] = edge;
// }

// Graph* createGraph(int v, int e){
//   Graph* graph = (Graph*)malloc(sizeof(Graph));
//   graph->V = v;
//   graph->E = e;
//   return graph;
// }

// int find(subset subsets[], int i){
//   if(subsets[i].parent != i) subsets[i].parent = find(subsets, subsets[i].parent);
//   return subsets[i].parent;
// }

// void Union(subset subsets[], int x, int y){
//   int xRoot = find(subsets, x);
//   int yRoot = find(subsets, y);

//   if(subsets[xRoot].rank < subsets[yRoot].rank) subsets[xRoot].parent = yRoot;
//   else if(subsets[xRoot].rank > subsets[yRoot].rank) subsets[yRoot].parent = xRoot;
//   else{
//     subsets[yRoot].parent = xRoot;
//     subsets[xRoot].rank++;
//   }
// }

// void Kruskal(Graph* graph){
//   int V = graph->V;
//   Edge result[V];
//   int e = 0;

//   MinHeap* heap = createMinHeap(graph->E);
//   for(int i = 0; i <graph->E; i++){
//     insertEdge(heap, graph->edges[i]);
//   }

//   subset* subsets = (subset*)malloc(sizeof(subset));
//   for(int v = 0; v < V; v++){
//     subsets[v].parent = v;
//     subsets[v].rank = 0;
//   }

//   while(heap->size > 0 && e < V-1){
//     Edge next = extractmin(heap);

//     int x = find(subsets, next.src);
//     int y = find(subsets, next.dest);

//     if(x != y){
//       result[e++] = next;
//       Union(subsets, x, y);
//     }
//   }
// }

/*
Prim's Algorithm
- Begins with a Tree, T, that contains a single vertex.
- Add a least cost edge (u,v) to T such that T U {(u,v)} is also a tree. 
- Repeat this edge addition set until T contains n-1 edges. 
- To make sure that the added edge does not form a cycle, at each step we choose the edge (u,v) such that exactly one of u or v is in T. 

Pseudocode
T = {};
TV = {0};

while(T contains fewer than n-1 edges){
  let (u,v) be a least cost edge such that u is in TV and v is not in TV;

  if(there is no such edge) break;
  add v to TV;
  add (u,v) to T;
}
if(T contains fewer than n-1 edges)
  printf("No spanning tree\n");
*/