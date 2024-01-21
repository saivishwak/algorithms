#include <stdio.h>

void print_array(int arr[], int size){
  for (int i = 0; i < size; i++){
    printf("%d\n", arr[i]);
  }
}

void insertion_sort(int arr[], int size){
  for (int i = 1; i < size; i++){
    int elem = arr[i];
    int j = i - 1;
    if (arr[j] > elem){
      //Swap the elems
      int temp = arr[j];
      arr[j] = elem;
      arr[i] = temp;
    }
    while (j > 0 && arr[j] < arr[j-1]){
      //Swap
      int temp = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
}

int main(){
  int arr[] = {6, 5, 7, 7, 8, 4, 3, 2, 1, 0, 23};
  int size = sizeof(arr) / sizeof (arr[0]);
  insertion_sort(arr, size);
  print_array(arr, size);
  return 0;
}
