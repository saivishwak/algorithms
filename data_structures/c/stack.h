#include "vector.h"

#ifndef STACK_H
#define STACK_H

#define STACK_INIT_CAPACITY 10;

typedef struct Stack{
  vector items;
  int capacity;
  int total;
} stack;

void init_stack(stack *);

void stack_push(stack *, void *);

void* stack_pop(stack *);

void free_stack(stack *);

#endif
