#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "vector.h"

BinTreeNode* create_new_binary_tree_node(void* data){
  BinTreeNode* new_node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
  init_binary_tree_node(new_node, data);
}

void init_binary_tree_node(BinTreeNode *node, void* data){
  node->data = data;
  node->left = node->right = NULL;
}

BinTreeNode* init_binary_tree(void* data){
  return create_new_binary_tree_node(data);
};

// The reason to do BinTreeNode** node is we need reference to the node pointer to update the value of it
// Else we will be assinging value to NULL which is pointing to nowhere...
void binary_tree_insert(BinTreeNode **node, void *item, int size){
  //Assuming insertion to follow complete binary tree
  vector vec;
  init_vector(&vec, 0);
  vector_add(&vec, *node);
  int index = 0;
  BinTreeNode* new_node = create_new_binary_tree_node(item);
  while (index < size){
    BinTreeNode* top = vec.items[index];
    if (top->left != NULL){
      vector_add(&vec, top->left);
    }
    else {
      top->left = new_node;
      break;
    }
    if (top->right != NULL){
      vector_add(&vec, top->right);
    }
    else {
      top->right = new_node;
      break;
    }
    index++;
  }
};

void free_binary_tree(BinTreeNode *root){
};
