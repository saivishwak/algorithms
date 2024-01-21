#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int size){
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

void swap(int *a, int*b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

void insert_into_heap(int arr[], int data, int size){
  //INsert into heap
  arr[size] = data;
  int parent = (size - 1) / 2;
  while (parent >= 0 && arr[parent] < data){
    swap(&arr[parent], &arr[size]);
    size = parent + 1;
    parent = (size - 1) / 2;
  }
}

void max_heapify(int data[], int size, int heap_at_index){
  int left_child = 2 * heap_at_index + 1;
  int right_child = 2 * heap_at_index + 2;
  int largest_index;
  if (left_child > size && right_child > size){
    return;
  }

  if (left_child < size && data[heap_at_index] < data[left_child]){
    largest_index = left_child;
  }
  if (right_child < size && data[right_child] > data[largest_index]){
    largest_index = right_child;
  }
  if (largest_index != heap_at_index){
    swap(&data[largest_index], &data[heap_at_index]);
    max_heapify(data, size, largest_index);
  }
}

int delete_root(int arr[], int* size){
  int root = arr[0];
  arr[0] = arr[*size - 1];
  *size =  *size - 1;
  max_heapify(arr, *size, 0);
  return root;
}

/*
 * Delete the root of the heap (for a heap the max value is at root) add it to the end of arr and repeat the proccess
*/
void heap_sort(int data[], int size, int sorted[]){
  int arr[size];
  for (int i = 0; i < size; i++){
    insert_into_heap(arr, data[i], i); 
  }
  int n = size;
  while (n > 0){
    int root = delete_root(arr, &n);
    sorted[n] = root;
  }
}

int main(){
  int data[] = {6, 7, 4, 2 ,3, 2, 1};
  int size = sizeof(data) / sizeof (data[0]);
  int temp_size = size;
  int sorted[size];
  heap_sort(data, size, sorted);
  print_array(sorted, temp_size);
  return 0;
}
