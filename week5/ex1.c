#include <stdio.h>
#include <pthread.h>

void *tread_func( int param );

int main( void )
{
  int n = 100, i;

  for (i = 0; i < n; i++)
  {
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    printf("\nThread %d create\n", i);
    pthread_create(&tid, &attr, tread_func, i);

    pthread_join(tid, NULL);
    printf("Thread %d exit\n", i);
  } 
  return 0;
}

void *tread_func( int param )
{
  printf("This is %d thread\n", param);
  pthread_exit(0);
}
