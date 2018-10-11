#include <stdlib.h>

int main ( void )
{
  int i;
  char *ptr;

  for ( i = 0; i < 10; i++)
  {
     ptr = malloc(10 * (sizeof(char) << 20));
     memset(ptr, NULL, 10 * (sizeof(char) << 20));
     sleep(1);
  }

  return 0;
}
