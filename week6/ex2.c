#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main ( void )
{
  int cpid, file_pipes[2];
  char data[] = "Test string", buffer[BUFSIZ + 1] = "";

  pipe( file_pipes );
  cpid = fork();
  
  if ( cpid == 0 )
  {
    printf( "Aus das Kind.\t" );
    read( file_pipes[0], buffer, BUFSIZ );
    printf( "Lesen: %s\n", buffer );
  }
  else
  {
    printf( "Aus der Vater.\t");
    write( file_pipes[1], data, strlen( data ) );
    printf( "Schreiben: %s\n", data );
  }

  return EXIT_SUCCESS;
}

