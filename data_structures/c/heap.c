#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "heap.h"

HeapNode* create_new_heap_node(void *data){
  HeapNode* new_node = (HeapNode *)malloc(sizeof(HeapNode));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
};

HeapNode* init_heap(void* data){
  return create_new_heap_node(data);
};

struct InsertNodeReturnTuple{
  int index;
  HeapNode* node;
};

struct InsertNodeReturnTuple insert_node(HeapNode* root, void* data, int size, vector* queue){
  vector_add(queue, root);
  HeapNode* new_node = create_new_heap_node(data);
  int index = 0;
  while (index < size){
    HeapNode* top = queue->items[index];
    if (top == NULL) continue;
    if (top->left != NULL) vector_add(queue, top->left);
    else {
      top->left = new_node;
      break;
    }
    if (top->right != NULL) vector_add(queue, top->right);
    else {
      top->right = new_node;
      break;
    }
    index++;
  };
  struct InsertNodeReturnTuple tup = {index, new_node};
  return tup;
}

void heap_insert(HeapNode* root, void* data, int size, bool (*data_check)(HeapNode*, HeapNode*)){
  vector queue;
  init_vector(&queue, 0);
  struct InsertNodeReturnTuple tup = insert_node(root, data, size, &queue);
  //Shuffle the inserted_node
  HeapNode* inserted_node = tup.node;
  //The parent index of the inserted_node
  int index = tup.index;
  HeapNode* current_node = inserted_node;
  while (index >= 0){
    HeapNode* parent_node = queue.items[index];
    bool can_shuffle = data_check(current_node, parent_node);
    if (can_shuffle){
      void* temp_data = parent_node->data;
      parent_node->data = current_node->data;
      current_node->data = temp_data;
    }
    else {
      break;
    }
    current_node = parent_node;
    //As all the previous nodes must be filled and is a BT the parent will be n-2
    if (index > 0 && index - 2 < 0) {
      index = 0;
    }
    else{
      index -= 2;
    }
  }
  delete_vector(&queue);
};

void free_heap(HeapNode* root, int size){
  vector queue;
  init_vector(&queue, 0);
  vector_add(&queue, root);
  int index = 0;
  while (index < size){
   HeapNode* top = (HeapNode *)queue.items[index];
    if (top->left != NULL) vector_add(&queue, top->left);
    if (top->right != NULL) vector_add(&queue, top->right);
    free(top);
    index++;
  }
  delete_vector(&queue);
}
