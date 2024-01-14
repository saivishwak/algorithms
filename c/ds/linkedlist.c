#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

void init_node(node* node, void *data){
  node->data=data;
  node->next = NULL;
}

void init_ll(node* head, void *data){
  init_node(head, data); 
}

void ll_push(node *head, void *data){
  node *curr_node = head;
  while (curr_node->next != NULL){
    curr_node = curr_node->next;
  }
  node* new_node = (node *)malloc(sizeof(node));
  init_node(new_node, data);
  curr_node->next = new_node;
}

void free_ll(node *head) {
  node *curr_node = head;
  while (curr_node != NULL) {
    node *next_node = curr_node->next;
    free(curr_node);
    curr_node = next_node;
  }
}

