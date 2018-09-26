#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void listener ( int ); 

int main ( void )
{
  signal( SIGINT, listener );

  while (1);

  return EXIT_SUCCESS;
}

void listener ( int sig )
{
  printf( "\nWarum mordst du mir?\n" );

  exit(EXIT_SUCCESS);
}
