#include <stdio.h>

main (void)
{ 
  int i, j, n;

  scanf("%d", &n);
  n += 1;

  for (j = 1; j != n; j++)
  {
    for (i = 1; i != (n - j); i++)
    {
      printf(" ");
    }

    for (i = 0; i != (2*j - 1); i++)
    {
      printf("*");
    }

    printf("\n");
  }
}
