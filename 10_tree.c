/*
Definition
A tree is a finite set of one or more nodes such that:
  There is a specially designated node called the root
  The remaining nodes are partitioned into n>=0 disjoint set where each of these sets is a tree

Terms
  Node: A basic unit of a tree. A node contains data and also may link to other nodes
  Degree of Node: Number of subtrees of the node
  Degree of Tree: maximum degree of the nodes in the tree
  Leaf(Terminal): A node with degree zero

Representation of Tree
  Left Child-Right Sibling Representation
  Degree-two Tree

Binary Tree
  Definition
    Either empty or consists of a root and two disjoint binary trees

  ADT Binary_Tree
  Objects: a finite set of nodes either empty or consisting of a root node, left and right
  Functions:
    BT Create(): creates an empty binary tree
    Boolean isEmpty(bt): if empty return TRUE
    BT MakeBT(bt1, item, bt2): return a BT whose left subtree is bt1 and right subtree is bt2 and root node contains data item
    BT Lchild(bt): if(isEmpty(bt)) return error, else return the left subtree of bt
    element Data(bt): if(isEmpty(bt)) return error, else return the data in the root node of bt
    BT Rchild(bt): if(isEmpty(bt)) return error, else return the right subtree of bt


Full Binary Tree
  A full BT of depth k is a BT having 2^k-1 nodes

Complete Binary Tree
  its nodes correspond to the nodes number from 1 to n in the full binary tree of depth k
*/

//Linked Representation
#include <stdio.h>
#include <stdlib.h>

struct node{
  char data;
  struct node *left_child, *right_child;
};

typedef struct node *tree_pointer;

/*
Binary Tree Traversals
  L: moving left
  V: visiting node
  R: moving right

  LVR: inorder traversal -> infix
  LRV: postorder traversal -> postfix
  VLR: preorder traversal -> prefix
*/

//inorder traversal
void inorder(tree_pointer ptr){
  if(ptr){
    inorder(ptr->left_child); //L
    printf("%c", ptr->data); //V
    inorder(ptr->right_child); //R
  }
}

//postorder traversal
void postorder(tree_pointer ptr){
  if(ptr){
    postorder(ptr->left_child); //L
    postorder(ptr->right_child); // R
    printf("%c", ptr->data); //V
  }
}

//preorder traversal
void preorder(tree_pointer ptr){
  if(ptr){
    printf("%c", ptr->data); // V
    preorder(ptr->left_child); // L
    preorder(ptr->right_child); // R
  }
}

/*
Iterative inorder traversal
  The previous implementation of inorder traversal was recursive.
  We can use a stack to implement inorder traversal in an iterative way. 
*/
#define MAX_SIZE_STACK 101

void iter_inorder(tree_pointer node){
  int top = -1; //initialize stack
  tree_pointer stack[MAX_SIZE_STACK];

  for( ; ; ){
    for( ; node ; node = node -> left_child)
      add(&top, node); //add to stack
    node = delete(&top); //delete from stack
    if(!node) break; //empty stack
    printf("%c", node->data);
    node = node->right_child;
  }
}

//Additional BT Operations
/*
Copying BT
  The function for copying a BT can be obtained by slightly modifying the function for postorder traversal
*/

tree_pointer copy(tree_pointer original){
  //returns a tree_pointer to an exact copy of the original tree
  tree_pointer temp;

  if(original){
    temp = (tree_pointer)malloc(sizeof(struct node));
    temp->left_child = copy(original->left_child);
    temp->right_child = copy(original->right_child);
    temp->data = original->data;

    return temp;
  }
  return NULL;
}

/*
Equality of BT
  A function for testing whether two binary trees are equal can be obtained by modifying the function for preorder traversal
*/

int isEqual(tree_pointer first, tree_pointer second){
  return((!first && !second) || first && second && (first->data == second -> data) && isEqual(first->left_child, second->left_child) && isEqual(first->right_child, first->left_child));
}

