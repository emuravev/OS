#include <stdio.h>

main (void)
{ 
  int i, n;

  printf("Select figure:\n\t1 - trinangle ver_1\n\t2 - triangle ver_2\n\t3 - triangle ver_3\n\t4 - rectangle ver_1\n\t5 - rectangle ver_2\nYour choise: ");
  scanf("%d", &i);
  
  printf("Enter n: ");
  scanf("%d", &n);

  if (i == 1)
  {
    print_triangle_1(n);
  }
  else if (i == 2)
  {
    print_triangle_2(n);
  }
  else if (i == 3)
  {
    print_triangle_3(n);
  }
  else if (i == 4)
  {
    print_rectangle_1(n);
  }
  else if (i == 5)
  {
    print_rectangle_2(n);
  }
  else
  {
    printf("Invalid argument %d\n", i);
  }

}

void print_triangle_1 (int n)
{
  int i, j; 
  n += 1;

  printf("\n");

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

  printf("\n");
}


void print_triangle_2 (int n)
{
  int i, j; 
  n += 1;

  printf("\n");

  for (j = 1; j != n; j++)
  {

    for (i = 0; i != j; i++)
    {
      printf("*");
    }

    printf("\n");
  }

  printf("\n");
}

void print_triangle_3 (int n)
{
  int i, j; 

  printf("\n");

  if (!(n % 2)) n += 1;

  for (j = 1; j != (int) (n-1)/2; j++)
  {
    for (i = 0; i != j; i++)
    {
      printf("*");
    }

    printf("\n");
  }

  for (j = (int) (n-1)/2; j != -1; j--)
  {
    for (i = 0; i != j; i++)
    {
      printf("*");
    }

    printf("\n");
  }
}

void print_rectangle_1 (int n)
{
  int i, j;
  n += 1;

  printf("\n");

  for (j = 1; j != n; j++)
  {
    for (i = 0; i != (2*n - 1); i++)
    {
      printf("*");
    }

    printf("\n");
  }

  printf("\n");
}

void print_rectangle_2 (int n)
{
  int i, j;
  n += 1;

  printf("\n");

  for (j = 1; j != n; j++)
  {
    for (i = 0; i != n - 1; i++)
    {
      printf("*");
    }

    printf("\n");
  }

  printf("\n");
}
