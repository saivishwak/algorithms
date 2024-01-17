#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

void print_ll(node* head){
  node *curr_node = head;
  printf("Printing LinkedList\n");
  while (curr_node != NULL){
    printf("%d\n", *(int *)curr_node->data);
    curr_node = curr_node->next;
  }
}

int main(){
  printf("LinkedList Implementation\n");
  node* head = (node *)malloc(sizeof(node));
  int a = 0, b = 1, c = 2, d = 3;
  init_ll(head, &a);
  ll_push(head,&b);
  ll_push(head,&c);
  ll_push(head,&d);
  print_ll(head);
  free_ll(head);
  return 0;
}
