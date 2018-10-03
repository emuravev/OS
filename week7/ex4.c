#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *myrealloc ( void*, size_t );

int main ( void )
{
	char *a = (char *) myrealloc(NULL, sizeof(char));
  a = (char *) myrealloc(a, 2*sizeof(char));
  a = (char *) myrealloc(a, 0);
  
	return 0;
}

void *myrealloc ( void *ptr, size_t newsize )
{
  if (ptr == NULL)
  {
    return malloc(newsize);
  }
  if (newsize == 0)
  {
    free(ptr);
    return NULL;
  }
  void * newmem = malloc(newsize);
  
  memcpy(newmem, ptr, newsize);

  return newmem;
}