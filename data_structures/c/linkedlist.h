#ifndef LL_H
#define LL_H

typedef struct Node{
  void *data;
  //We cannot use linkedlist directly here as typedef is not defined yet,
  // Hence using the complete struct name
  struct Node *next;
} node;

void init_ll(node *, void *);

void init_node(node* , void *);

void ll_push(node *, void *);

void free_ll(node *);

#endif
