#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include <stdbool.h>

void init_vector(vector* vec, int cap){
  //If cap == 0 then use default value of capacity else use user defined
  if (cap != 0){
    vec->capacity = cap;
  }
  else {
  vec->capacity = VECTOR_INIT_CAPACITY;
  }
  vec->total = 0;
  vec->items = malloc(sizeof(void *) * vec->capacity);
};


void vector_add(vector *vec, void *item){
  if (vec->total >= vec->capacity){
    //Create a vector with double the size
    vec->capacity = vec->capacity * 2;
    void **p = malloc(sizeof(void *) * vec->capacity);
    int len = vec->total;
    for (int i =0; i < len; i++){
      p[i] = vec->items[i];
    }
    free(vec->items);
    vec->items = p;
    // Add the item to the vecto
    vec->items[vec->total++] = item;
  }
  else {
    vec->items[vec->total++] = item;
  }
};

void* vector_pop(vector *v){
  if (v->total == 0){
    return NULL;
  }
  else {
    int len = v->total;
    void* item = v->items[len-1];
    v->items[len-1] = NULL;
    v->total = len-1;
    return item;
  }
}

bool vector_is_empty(vector * vec){
  return vec->total == 0;
}

void delete_vector(vector *v){
  free(v->items);
};

