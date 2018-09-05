#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

void bubble_sort(int *, int);

int main(void)
{
  int i, arr[ARR_SIZE];
  srand(time(NULL));

  printf("Array of integers: ");
  for (i = 0; i < ARR_SIZE; i++)
  {
    arr[i] = rand() % 1001;
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  bubble_sort(arr, ARR_SIZE);

  printf("Sorted array of integers: ");
  for (i = 0; i < ARR_SIZE; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

void bubble_sort(int *arr, int size)
{
  int i, is_swaped = 0, tmp;

  do
  {
    is_swaped = 0;
    for (i = 0; i < size; i++)
    {
      if (arr[i - 1] > arr[i])
      {
        tmp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = tmp;

        is_swaped = 1;
      }
    }

    size -= 1;
  } while(is_swaped);
}