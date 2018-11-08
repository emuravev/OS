#include <stdio.h>
#include <string.h>


int main(int argc, char * argv[])
{
  int i;
  FILE *f;

  if (argc == 3 && !strcmp(argv[1],"-a"))
  {
    f = fopen(argv[2], "a+");
  }
  else
  {
    f = fopen(argv[1], "w");
  }

  while ((i = getc(stdin)) != EOF)
  {
    fputc(i, stdout);
    fputc(i, f);
  }

  fclose(f);

  return 0;
}
  
