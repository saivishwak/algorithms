#include <stdio.h>

void print_array(int arr[], int size){
  for (int i = 0; i < size; i++){
    printf("%d\n", arr[i]);
  }
}

void selection_sort(int arr[], int size){
  for (int i = 0; i < size; i++){
    int first_elem = arr[i];
    //Find the minimum value
    int min_idx = i;
    for (int j = i + 1; j < size; j++){
      int elem = arr[j];
      int min_elem = arr[min_idx];
      if (elem < min_elem){
        min_idx = j;
      }
    }
    //Swapping
    arr[i] = arr[min_idx];
    arr[min_idx] = first_elem;
  }
}

int main(){
  int arr[] = {6, 5, 7, 7, 8, 4, 3, 2, 1};
  int size = sizeof(arr) / sizeof (arr[0]);
  selection_sort(arr, size);
  print_array(arr, size);
  return 0;
}
