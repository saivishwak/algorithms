#include <stdint.h>
#include <stdlib.h>
#include "vector.h"

#ifndef HEAP_H
#define HEAP_H

// We are considering to create a Min and Max Heap which are complete binary trees
typedef struct HeapNode{
  void* data;
  struct HeapNode* left;
  struct HeapNode* right;
} HeapNode;

HeapNode* init_heap(void*);

HeapNode* create_new_heap_node(void*);

void heap_insert(HeapNode*, void *, int, bool (*)(HeapNode*, HeapNode*));

void free_heap(HeapNode*, int);

#endif
