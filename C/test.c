#include <stdio.h>
#include <stdlib.h> 
#define ARR_ARRAY_LENGTH 5
#define ARR2_ARRAY_LENGTH 6
#define ARR3_ARRAY_LENGTH 7

typedef struct Array {
  void* array;
  size_t arrayLength; // elements is array
  size_t itemSize; // size of each element in bytes
} Array;

// https://www.tutorjoes.in/c_programming_tutorial/generic_in_c

int main() {
  /****************************************/
  // int a[]={10,20,30,40,50};
  // void *p; // a void pointer
  // p=a; // p has the memory address of a[0]
  // printf("\n%d\n",*(int *)p); //  The pointer is casted to int pointer using (int *) before dereferencing.
  /****************************************/

  // for (int i = 0; i < ARRAY_LENGTH; i++) {
  //   printf("\n%d\n",*(int *)arr[i]);
  // }

  /******* Assign values to an array *******/
  // void **arr = malloc(sizeof(void *) * ARRAY_LENGTH);
  void **arr = malloc(ARR_ARRAY_LENGTH*sizeof(int));
  for (int i = 0; i < ARR_ARRAY_LENGTH; i++) {
      arr[i] = 5;
  }

  // Print array 
  for (int i = 0; i < ARR_ARRAY_LENGTH; i++) {
    printf(" %d ",*(arr+i));
  }
  printf("\n\n");

  /******* Insert at head of array *******/
  void **arr2 = malloc((ARR2_ARRAY_LENGTH)*sizeof(int));

  for (int i = 0; i < ARR2_ARRAY_LENGTH; i++) {
    arr2[i+1] = arr[i];
  }
  arr2[0] = 10;

  // Print array 
  for (int i = 0; i < ARR2_ARRAY_LENGTH; i++) {
    printf(" %d ",*(arr2+i));
  }
  printf("\n\n");
  free(arr);

  /******* Append to array *******/
  void **arr3 = malloc((ARR3_ARRAY_LENGTH)*sizeof(int));

  for (int i = 0; i < ARR2_ARRAY_LENGTH; i++) {
    arr3[i] = arr2[i];
  }
  arr3[ARR3_ARRAY_LENGTH-1] = 16;

  // Print array 
  for (int i = 0; i < ARR3_ARRAY_LENGTH; i++) {
    printf(" %d ",*(arr3+i));
  }
  printf("\n\n");
  free(arr2);


  // printf() displays the string inside quotation
  printf("\nHello, World!");
  return 0;
}