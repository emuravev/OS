#include <stdio.h>

int main( void )
{
  char str [5];
  setvbuf(stdout, str, _IOLBF, 5);
  
  putc ('H', stdout);
  sleep(1);
  putc ('e', stdout);
  sleep(1);
  putc ('l', stdout);
  sleep(1);
  putc ('l', stdout);
  sleep(1);
  putc ('o', stdout);
  sleep(1);
  fclose(stdout);

  return 0; 
}