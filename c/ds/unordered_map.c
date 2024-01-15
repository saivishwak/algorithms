#include<stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "unordered_map.h"

void init_map(map *m){
  m->items = malloc(sizeof(item) * (int)CAPACITY);
};

//https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1a_hash
uint64_t hash_key(char* key) {
  uint64_t hash = FNV_OFFSET;
  for (const char* p = key; *p; p++) {
    hash ^= (uint64_t)(unsigned char)(*p);
    hash *= FNV_PRIME;
  }
  return hash;
};

void map_insert(map *m, item *it){
  //Calculate the hash of the string;
  char *key = it->key;
  size_t index = (size_t)(hash_key(key) % (uint64_t)CAPACITY);
  printf("Inserting Item in index %ld\n", index);
  m->items[index] = it;
};


item* map_get(map *m, char *key){
  //Calculate the hash of the string;
  size_t index = (size_t)(hash_key(key) % (uint64_t)CAPACITY);
  return m->items[index];
};

void map_remove(map *m, char *key){
  //Calculate the hash of the string;
  size_t index = (size_t)(hash_key(key) % (uint64_t)CAPACITY);
  m->items[index] = NULL;
};



void free_map(map *m){
  free(m->items);
};
