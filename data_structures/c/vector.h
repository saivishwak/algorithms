#include <stdbool.h>
#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 10;

typedef struct Vector{
  void **items;
  int capacity;
  int total;
} vector;

void init_vector(vector *, int);

void vector_add(vector *, void *);

void* vector_pop(vector *);

bool vector_is_empty(vector *);

void delete_vector(vector *);

#endif
