#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Max(x,y) (((x)>(y)) ? (x):(y))

typedef struct AvlNode {
  int data;
  struct AvlNode *left, *right;
  int Height;
} AvlNode;

int height(AvlNode* node) {
  if (node == NULL) {
    return -1;
  } else {
    return node->Height;
  }
}

AvlNode* rotateLL(AvlNode* p) {
  AvlNode* c = p->left;
  p->left = c->right;
  c->right = p;

  p->Height = Max(height(p->left), height(p->right)) + 1;
  c->Height = Max(height(c->left), p->Height) + 1;
  return c;
}

AvlNode* rotateRR(AvlNode* p) {
  AvlNode* c = p->right;
  p->right = c->left;
  c->left = p;

  p->Height = Max(height(p->left), height(p->right)) + 1;
  c->Height = Max(p->Height, height(c->right)) + 1;
  return c;
}

AvlNode* rotateLR(AvlNode* p) {
  AvlNode* c = p->left;
  p->left = rotateRR(c);
  return rotateLL(p);
}

AvlNode* rotateRL(AvlNode* p) {
  AvlNode* c = p->right;
  p->right = rotateLL(c);
  return rotateRR(p);
}

AvlNode* avlAdd(AvlNode* root, int data) {
  if (root == NULL) {
    root = (AvlNode*)malloc(sizeof(AvlNode));
    if (root == NULL) exit(1);
    root->data = data;
    root->Height = 0;
    root->left = root->right = NULL;
  } else if (data < root->data) {
    root->left = avlAdd(root->left, data);
    if (height(root->left) - height(root->right) == 2) {
      if (data < root->left->data) {
        root = rotateLL(root);
      } else {
        root = rotateLR(root);
      }
    }
  } else if (data > root->data) {
    root->right = avlAdd(root->right, data);
    if (height(root->right) - height(root->left) == 2) {
      if (data > root->right->data) {
        root = rotateRR(root);
      } else {
        root = rotateRL(root);
      }
    }
  } else {
    printf("중복 키 삽입 오류\n");
    exit(1);
  }

  root->Height = Max(height(root->left), height(root->right)) + 1;
  return root;
}

AvlNode* avlSearch(AvlNode* node, int key) {
  if (node == NULL) return NULL;
  if (key == node->data) return node;
  else if (key < node->data)
    return avlSearch(node->left, key);
  else
    return avlSearch(node->right, key);
}

void inorderTraveling(AvlNode* root) {
  if (root != NULL) {
    inorderTraveling(root->left);
    printf("%d ", root->data);
    inorderTraveling(root->right);
  }
}

AvlNode* avlDelete(AvlNode* root, int key) {
  if (root == NULL) return NULL;

  if (key < root->data) {
    root->left = avlDelete(root->left, key);
  } else if (key > root->data) {
    root->right = avlDelete(root->right, key);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left == NULL || root->right == NULL) {
      AvlNode* subtree = (root->left != NULL) ? root->left : root->right;
      free(root);
      return subtree;
    } else {
      AvlNode* succ = root->right;
      while (succ->left != NULL)
        succ = succ->left;

      root->data = succ->data;
      root->right = avlDelete(root->right, succ->data);
    }
  }

  root->Height = Max(height(root->left), height(root->right)) + 1;

  int balance = height(root->left) - height(root->right);

  if (balance > 1) {
    if (height(root->left->left) >= height(root->left->right))
      return rotateLL(root);
    else
      return rotateLR(root);
  }
  if (balance < -1) {
    if (height(root->right->right) >= height(root->right->left))
      return rotateRR(root);
    else
      return rotateRL(root);
  }

  return root;
}

int main() {
  AvlNode* root = NULL;

  root = avlAdd(root, 7);
  root = avlAdd(root, 8);
  root = avlAdd(root, 9);
  root = avlAdd(root, 2);
  root = avlAdd(root, 1);
  root = avlAdd(root, 5);
  root = avlAdd(root, 3);
  root = avlAdd(root, 6);
  root = avlAdd(root, 4);

  inorderTraveling(root);
  printf("\nRoot node: %d(h=%d)\n", root->data, root->Height);

  root = avlDelete(root, 8);
  inorderTraveling(root);
  printf("\nRoot node: %d(h=%d)\n", root->data, root->Height);

  root = avlDelete(root, 2);
  inorderTraveling(root);
  printf("\nRoot node: %d(h=%d)\n", root->data, root->Height);

  return 0;
}
