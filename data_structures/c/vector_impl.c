#include<stdio.h>
#include<stdlib.h>
#include "vector.h"

void print_vector(vector* vec){
  int len = vec->total;
  printf("-- printing vector of len -> %d --\n", len);
  for (int i =0; i < len; i++){
    printf("%d\n", *(int *)vec->items[i]);
  }
}

int main(){
  printf("Vector Implemtation\n");
  vector vec;
  init_vector(&vec, 0);
  printf("Capacity of Vector -> %d\n", vec.capacity);
  int a = 10;
  int b = 12;
  int c = 13;
  int d = 14;
  int e = 15;
  int f = 16;
  vector_add(&vec, &a);
  vector_add(&vec, &b);
  vector_add(&vec, &c);
  vector_add(&vec, &d);
  vector_add(&vec, &e);
  vector_add(&vec, &f);
  print_vector(&vec);
  vector_pop(&vec);
  print_vector(&vec);
  vector_pop(&vec);
  print_vector(&vec);
  delete_vector(&vec);
  return 0;
}
