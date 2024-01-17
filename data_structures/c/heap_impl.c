#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void level_order_print(HeapNode* root, int size){
  vector queue;
  init_vector(&queue, 0);
  vector_add(&queue, root);
  int index = 0;
  while (index < size){
    HeapNode* top = (HeapNode *)queue.items[index];
    printf("%d -> ",  *(int *)top->data);
    if (top->left != NULL) vector_add(&queue, top->left);
    if (top->right != NULL) vector_add(&queue, top->right);
    index++;
  }
  delete_vector(&queue);
  printf("\n");
}

bool data_check(HeapNode* current_node, HeapNode* parent_node) 
{ 
  int current_node_data = *((int *)current_node->data);
  int parent_node_data = *((int *)parent_node->data);
  return parent_node_data <= current_node_data;
} 

bool data_check_min(HeapNode* current_node, HeapNode* parent_node) 
{ 
  int current_node_data = *((int *)current_node->data);
  int parent_node_data = *((int *)parent_node->data);
  return parent_node_data >= current_node_data;
} 

int main(){
  int data[] = {10, 20, 100};
  int size = sizeof(data) / sizeof(data[0]);
  //Init a max heap
  HeapNode* root = init_heap(&data[0]);
  for (int i = 1; i < size; i++){
    heap_insert(root, &data[i], size, &data_check);
  }
  int a = 900;
  heap_insert(root, &a, size+1, &data_check);
  level_order_print(root, size+1);

  //Init Min Heap
  int data_min[] = {5, 6, 7, 4, 2};
  int size_min = sizeof(data_min) / sizeof(data_min[0]);

  HeapNode* root_min = init_heap(&data_min[0]);
  for (int i = 1; i < size_min; i++){
    heap_insert(root_min, &data_min[i], size_min, &data_check_min);
  }
  level_order_print(root_min, size_min);

  free_heap(root, size+1);
  free_heap(root_min, size_min);
  return 0;
}
