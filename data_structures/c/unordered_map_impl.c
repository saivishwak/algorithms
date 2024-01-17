#include<stdio.h>
#include <stdlib.h>
#include "unordered_map.h"

int main(){
  map m;
  init_map(&m);
  struct Item it1 = {"test", 0};
  struct Item it2 = {"user", 1};
  map_insert(&m, &it1);
  map_insert(&m, &it2);
  item* g = map_get(&m, "test"); 
  printf("%d\n", g->value);
  item* g1 = map_get(&m, "user"); 
  printf("%d\n", g1->value);
  map_remove(&m, "test");
  item* g2 = map_get(&m, "test"); 
  printf("%p\n", (void *)g2);
  free_map(&m);
  return 0;
}
