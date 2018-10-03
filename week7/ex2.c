#include <stdio.h>
#include <stdlib.h>

int main ( void )
{
  int n, i, *arr;
  scanf("%d", &n);
  
  arr = (int *) calloc(n, sizeof(int));
  
  for (i = 0; i < n; i++)
  {
    arr[i] = i;
    printf("%d ", i);
  }
  printf("\n");

  free(arr);
  
  return 0;
}