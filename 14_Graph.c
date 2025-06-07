/*
Starting at any vertex, going through each edge exactly once and terminating at the start vertex iff the degree of each vertex is even. 

A graph G consists of two sets, V and E.
V: vertices
E: set of pairs of vertices, these pairs are called edges. 
V(G) and E(G) represent the sets of vertices and edges of G
G = (V, E)

Graph with self loops: A graph that has an edge from a vertex, v, back to itself
MultiGraph: A graph allowing multiple edges between a pair of nodes
Complete Graph: A graph with n vertices has exactly n(n-1)/2 edges

(u,v): vertices u and v are adjacent. Edge(u,v) is incident on vertices u and v.
<u,v>: u is adjacent to v, and v is adjacent from u.

Graph Representations
  adjacency matrix
  adjacency list 

Elementary Graph operations
  DFS
  BFS

DFS
  1. visit the starting vertex v
  2. select an unvisited vertex from v's adjacent vertices
  3. recursively repeat this process
*/

// #include <stdio.h>
// #include <stdlib.h>
// #define TRUE 1
// #define FALSE 0

// typedef struct node *nodePointer;
// typedef struct node{
//   int vertex;
//   nodePointer link;
// }Node;

// nodePointer graph[101];
// int visited[101];

// void addEdge(int u, int v){
//   nodePointer newNode = (nodePointer)malloc(sizeof(Node));
//   newNode->vertex = v;
//   newNode->link = graph[u];
//   graph[u] = newNode;
// }

// void dfs(int v){
//   nodePointer w;
//   visited[v] = TRUE;
//   printf("%5d", v);
//   for(w = graph[v]; w; w = w->link){
//     if(!visited[w->vertex]) dfs(w->vertex);
//   }
// }

/*
BFS
  1. visit the starting vertex v. 
  2. visit each of the adjacent vertices of v. 
  3. visit all the unvisited vertices that are adjacent to the first adjacent vertex of v. 
  4. visit all the unvisited vertices that are adjacent to the second adjacent vertex of v.
  5. continue this process until we have visited all vertices.
*/

// #include <stdio.h>
// #include <stdlib.h>
// #define TRUE 1
// #define FALSE 0

// typedef struct node* nodePointer;
// typedef struct node{
//   int vertex;
//   nodePointer link;
// }Node;

// int visited[101];
// nodePointer graph[101];

// typedef struct{
//   int items[101];
//   int front;
//   int rear;
// }Queue;

// void initQueue(Queue* q){
//   q->front = 0;
//   q->rear = -1;
// }

// int isEmpty(Queue *q){
//   return(q->rear < q->front);
// }

// void enqueue(Queue* q, int value){
//   q->items[++(q->rear)] = value;
// }

// int dequeue(Queue *q){
//   if (isEmpty(q)) return -1;
//   return q->items[(q->front)--];
// }

// void addEdge(int u, int v){
//   nodePointer newNode = (nodePointer)malloc(sizeof(Node));
//   newNode->vertex = v;
//   newNode->link = graph[u];
//   graph[u] = newNode;
// }

// void bfs(int start){
//   Queue q;
//   initQueue(&q);

//   visited[start] = TRUE;
//   printf("%5d", start);
//   enqueue(&q, start);

//   while(!isEmpty(&q)){
//     int node = dequeue(&q);
//     nodePointer temp = graph[node];

//     while(temp){
//       int next = temp->vertex;
//       if(!visited[next]){
//         printf("%5d", next);
//         visited[next];
//         enqueue(&q, next);
//       }
//       temp = temp->link;
//     }
//   }
// }

/*
Spanning Tree
- A spanning tree of graph G is any "tree" that consists of edges in G and that includes all ther vertices of G.
- A spanning tree is a minimal subgraph of G' of G such that V(G') = V(G) and G' is connected.
- When performing DFS or BFS, the search implicitly partitions the edges in G into two sets
  T: the set of edges used during the search
  N: the set of remaining edges

Biconnected Components
- Articulation point: a vertex v of G such that the deletion of v, together with all edges incident on v, produces a graph G' that has at least two connected component
- Biconnected graph is a connected graph that has no articulation points.

=> Finding articulation points in a graph
- Simple method
  1. remove v from graph
  2. see if graph remains connected
  3. add v back to graph

- Advanced method
  1. Get a spanning tree of the graph using DFS

*/
// #include <stdio.h>
// #include <stdlib.h>
// #define MIN2(x,y) ((x) < (y) ? (x) : (y))

// typedef struct node* nodePointer;
// typedef struct node{
//   int vertex;
//   nodePointer link;
// }Node;

// nodePointer graph[101];
// int dfn[101], low[101], num = 0;
// int isArticulation[101];

// void dfnlow(int u, int v){
//   nodePointer ptr;
//   int w;
//   dfn[u] = low[u] = num++;
//   for(ptr = graph[u]; ptr; ptr = ptr->link){
//     w = ptr->vertex;
//     if(dfn[w] < 0){
//       dfnlow(w,u);
//       low[u] = MIN2(low[u], low[w]);
//     }
//     else if(w != v) low[u] = MIN2(low[u], dfn[w]);
//   }
// }