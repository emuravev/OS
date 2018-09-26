#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main ( void )
{
  int cpid = 1, i;
  
  cpid = fork();

  if ( cpid == 0 )
  {
    printf( "Aus das Kind\n" );
    for (i == 0; i < 10; i++)
    {
      printf( "I'm alive\n" );
      sleep( 1 );
    }
  }
  else
  {
    printf( "Aus der Vater\n" );
    sleep( 10 );
    kill( cpid, SIGTERM );
    printf( "Vater mordt das Kind\n" );
  }

  return EXIT_SUCCESS;
}

