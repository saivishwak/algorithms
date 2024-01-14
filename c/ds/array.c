#include <stdio.h>

int main(){
  //In this use case size of array is taken to be 2
  int arr[] = {0, 1};
  printf("%d \n", arr[1]);

  //in this case size is 2 and default value is 0 for all elements
  int arr2[2] = {10};
  printf("%d", arr2[0]);
  printf("\n");

  //Just decalare the array without default value
  int arr3[5];
  printf("%d", arr3[0]);
  printf("\n");
  return 0;
:}
