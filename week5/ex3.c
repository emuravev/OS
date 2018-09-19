#include <stdio.h>
#include <pthread.h>

void *tread_func( void *param );

int main( void )
{
  pthread_t tid_1, tid_2;
  pthread_attr_t attr_1, attr_2;

  pthread_attr_init(&attr_1);
  pthread_attr_init(&attr_2);

  pthread_create(&tid_1, &attr_1, tread_func, 1);
  pthread_create(&tid_2, &attr_2, tread_func, 2);
  pthread_join(tid_1, NULL);
  pthread_join(tid_2, NULL);

  return 0;
}

void *tread_func( void *param )
{
  int i;

  for (i = 0; i < 10; i++)
  {
    printf("Message from %d thread\n", param);
    sleep(1);  
  }

  pthread_exit(0);
}
