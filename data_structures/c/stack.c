#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "stack.h"


void init_stack(stack *s){
  s->capacity = STACK_INIT_CAPACITY;
  s->total = 0;
  vector v;
  init_vector(&v, s->capacity);
  s->items = v;
}


void stack_push(stack *s, void *item){
  vector_add(&s->items, item);
  s->total++;
}


void* stack_pop(stack *s){
  s->total--;
  return vector_pop(&s->items);
}

void free_stack(stack *s){
  delete_vector(&s->items);
}
