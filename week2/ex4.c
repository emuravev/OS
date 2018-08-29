#include <stdio.h>

void swap(int*, int*);

main (void)
{ 
  int a, b;

  printf("Enter the first integer: ");
  scanf("%d", &a);

  printf("Enter the second integer: ");
  scanf("%d", &b);

  swap(&a, &b);

  printf("They are swapped!\n");

}

void swap (int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
