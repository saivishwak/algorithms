#include <stdio.h>

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

/*
 * Find any element that is less than the pivot and swap it with the first found largest number
 * and then swap the next largest number with the pivot
*/
int partition(int arr[], int begin, int end){
  int pivot = end;
  int pivot_elem = arr[pivot];
  int i = begin;
  for (int j = begin; j < end; j++){
    if (arr[j] <= pivot_elem){
      swap(&arr[j], &arr[i]);
      i++;
    }
  }
  swap(&arr[pivot], &arr[i]);
  return i;
}

void quick_sort(int arr[], int begin, int end){
  if (begin > end){
    return;
  }
  //Choosing pivot as end
  int pivot = partition(arr, begin, end);
  quick_sort(arr, begin, pivot - 1);
  quick_sort(arr, pivot + 1, end);
}

int main(){
  int arr[] = {5, 3, 4, 1, 0, 2};
  int size = sizeof(arr) / sizeof (arr[0]);
  quick_sort(arr, 0, size - 1);
  print_array(arr, size);
  return 0;
}
