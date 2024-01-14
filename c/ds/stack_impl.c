#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void print_stack(stack* s){
  int len = s->total;
  printf("-- printing stack of len -> %d --\n", len);
  for (int i =0; i < len; i++){
    printf("%d\n", *(int *)s->items.items[i]);
  }
}

int main(){
  printf("Stack Implemtation\n");
  stack s;
  init_stack(&s);
  int a = 1, b = 2;
  stack_push(&s, &a);
  stack_push(&s, &b);
  print_stack(&s);
  stack_pop(&s);
  print_stack(&s);
  free_stack(&s);

  stack s1;
  init_stack(&s1);
  int a1 = 10, b1 = 11;
  stack_push(&s1, &a1);
  stack_push(&s1, &b1);
  print_stack(&s1);
  stack_pop(&s1);
  print_stack(&s1);
  free_stack(&s1);
  return 0;
}
