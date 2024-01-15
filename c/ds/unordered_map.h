#include <stdint.h>
#ifndef UNORDERED_MAP

#define UNORDERED_MAP

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL
#define CAPACITY 100

// As generics are not possible in c and using void* is not great we are sticking
// with key as string
typedef struct Item {
  char* key;
  int value;
} item;

typedef struct Map {
  item** items;
} map;

uint64_t hash_key(char *);

void init_map(map *);

void map_insert(map *, item *);

item* map_get(map *, char *);

void map_remove(map *, char *);

void free_map(map *);

#endif // !UNORDERED_MAP
