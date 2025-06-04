/*
Definition
- A BST is a BT that has the following properties
  Each node has one distinct key
  The keys in the left subtree are smaller than the key in the root
  The keys in the right subtree are larger than the key in the root
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int key;
}element;

typedef struct treeNode* treepointer;
typedef struct treeNode{
  element data;
  treepointer leftChild, rightChild;
}treeNode;

//recursive
element* search(treepointer root, int k){
  //return a pointer to the element whose key is k, if there is no such element, return NULL
  if(!root)return NULL;
  if(k == root->data.key)return &(root->data);
  if(k < root->data.key)return search(root->leftChild, k);
  return search(root->rightChild, k);
}

//iterative
element* iterSearch(treepointer root, int k){
  while(root){
    if(k == root->data.key)return &(root->data);
    if(k < root->data.key) root = root->leftChild;
    else root = root->rightChild;
  }
  return NULL;
}

treepointer modifiedSearch(treepointer node, int k){
  treepointer parent = NULL;
  while(node){
    if(k == node->data.key) return NULL; //이미 존재
    parent = node;
    if(k < node->data.key) node = node->leftChild;
    else node = node->rightChild;
  }
  return parent;
}

//insertion
void insertNode(treepointer *node, int k){
  treepointer ptr, temp = modifiedSearch(*node, k);
  
  if(temp || !(*node)){
    ptr = (treepointer)malloc(sizeof(*ptr));
    ptr->data.key = k;
    ptr->leftChild = ptr->rightChild = NULL;

    if(*node){
      if(k < temp->data.key) temp->leftChild = ptr;
      else temp->rightChild = ptr;
    }
    else *node = ptr;
  }
}

/*
deletion
1. If the node does not exist, we are done
2. If the node is a leaf node
  - Set the corresponding child field of its parent to NULL and free the node
3. If the node is a non-leaf node with single child
  - Place the single child in the place of the deleted node
4. If the node is a non-leaf node with two children
  - Replace the deleted node with either the largest element in its left subtree or the smallest element in its right subtree
  - Delete this replacing element from the subtree from which it was taken
*/

void delete(treepointer *node, int k){
  treepointer temp, parent;

  if(*node == NULL) return; // case 1

  if(k < (*node)->data.key) delete(&((*node)->leftChild), k);
  else if(k > (*node)->data.key) delete(&((*node)->rightChild), k);
  else{
    treepointer target = *node; // 노드 발견
    if(target->leftChild == NULL && target->rightChild == NULL){
      free(target);
      *node = NULL; // case 2
    }
    else if(target->leftChild != NULL && target->rightChild == NULL){
      *node = target->leftChild;
      free(target); // case 3 - left child
    }
    else if(target->leftChild == NULL && target->rightChild != NULL){
      *node = target->rightChild;
      free(target); //case 3 - right child
    }
    else{ // case 4
      treepointer succParent = target;
      treepointer succ = target->rightChild;

      while(succ->leftChild){
        succParent = succ;
        succ = succ->leftChild;
      }

      target->data = succ->data;

      if(succParent->leftChild = succ) delete(&(succParent->leftChild), succ->data.key);
      else delete(&(succParent->rightChild),succ->data.key);
    }
  }
}

/*
Winner Tree
- complete BT
- tournament player
- each internal node represents a match played between its two children, the winner of the match is stored at the internal node
- root node has the overall winner

1. After initializing the winner tree, we remove the key at the root
2. Replace the key of the winner with a large number
3. Do rematch until all players are removed
-> sorting is done

Time complexity
- Initializing: O(n)
- Removing/Replacing: O(log n)
- Sorting: O(nlog n)
*/