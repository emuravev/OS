#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main ( void )
{
  int i;
  char *ptr;
  struct rusage *mem_usage = malloc(sizeof(struct rusage));

  for ( i = 0; i < 10; i++)
  {
     ptr = malloc(10 * (sizeof(char) << 20));
     memset(ptr, NULL, 10 * (sizeof(char) << 20));
     getrusage(RUSAGE_SELF, mem_usage);
     printf("Memory: %ld bytes\n", mem_usage->ru_maxrss);
     sleep(1);
  }

  return 0;
}
