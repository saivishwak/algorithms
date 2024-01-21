#include <stdio.h>

void print_array(int arr[], int size){
  for (int i = 0; i < size; i++){
    printf("%d\n", arr[i]);
  }
}

void bubble_sort(int arr[], int size){
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size - 1; j++){
      int temp = arr[j];
      //Swap the elements
      if (arr[j] > arr[j+1]){
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

}

int main(){
  int arr[] = {6, 5, 7, 7, 8, 4, 3, 2, 1};
  int size = sizeof(arr) / sizeof (arr[0]);
  bubble_sort(arr, size);
  print_array(arr, size);
  return 0;
}
