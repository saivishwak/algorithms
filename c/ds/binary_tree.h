#include <stdint.h>
#include <stdlib.h>
#include "vector.h"
#ifndef BINARY_TREE_H

#define BINARY_TREE_H

typedef struct BinaryTreeNode{
  void* data;
  struct BinaryTreeNode* left;
  struct BinaryTreeNode* right;
} BinTreeNode;

BinTreeNode* create_new_binary_tree_node(void *);

void init_binary_tree_node(BinTreeNode *, void *);

BinTreeNode* init_binary_tree(void *);

void binary_tree_insert(BinTreeNode **, void *, int);

void free_binary_tree(BinTreeNode *);

#endif
