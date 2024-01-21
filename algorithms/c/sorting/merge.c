#include <stdio.h>

void print_array(int arr[], int size){
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

void merge(int arr[], int left, int middle, int right){
  int i, j, k;
  int left_sub_array_len =  middle - left + 1;
  int right_sub_array_len = right - middle;
  int left_sub_array[left_sub_array_len];
  int right_sub_array[right_sub_array_len];

  //Copy the elements from array to sub arrays
  for (i = 0; i < left_sub_array_len; i++){
    left_sub_array[i] = arr[left + i];
  }
  for (i = 0; i < right_sub_array_len; i++){
    right_sub_array[i] = arr[middle + 1 + i];
  }

  //Merge the temp arrays into arr
  i = 0;
  j = 0;
  k = left;
  while (i < left_sub_array_len && j < right_sub_array_len){
    if (left_sub_array[i] <= right_sub_array[j]) {
      arr[k] = left_sub_array[i];
      i++;
    }
    else {
      arr[k] = right_sub_array[j];
      j++;
    }
    k++;
  }
  while (i < left_sub_array_len){
    arr[k] = left_sub_array[i];
    i++;
    k++;
  }
  while (j < right_sub_array_len){
    arr[k] = right_sub_array[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int begin, int end){
  if (begin >= end){
    return;
  }
  int middle = begin + (end - begin) / 2;
  merge_sort(arr, begin, middle);
  merge_sort(arr, middle + 1, end);
  merge(arr, begin, middle, end);
}

int main(){
  int arr[] = {6, 5, 4, 3, 10, 9, 2, 2, 1, 0};
  int size = sizeof(arr) / sizeof (arr[0]);
  merge_sort(arr, 0, size);
  print_array(arr, size);
  return 0;
}
