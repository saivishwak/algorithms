#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

void inorder_print(BinTreeNode* node){
  if (node == NULL){
    return;
  }
  inorder_print(node->left);
  printf("%d -> ", *((int *)node->data));
  inorder_print(node->right);
};

int main(){
  int data[] = {8, 3, 10, 1, 6, 9};
  int size = sizeof(data) / sizeof(data[0]);
  BinTreeNode* root = init_binary_tree(&data[0]);
  for (int i = 1; i < size; i++){
    binary_tree_insert(&root, &data[i], size);
  }
  inorder_print(root);
  printf("\n");
  free_binary_tree(root);
  return 0;
}
