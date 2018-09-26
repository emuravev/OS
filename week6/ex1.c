#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main ( void )
{
  int file_pipes[2];
  char data[] = "Test string", buffer[BUFSIZ + 1] = "";

  pipe( file_pipes );
  write( file_pipes[1], data, strlen( data ) );
  printf( "Write: %s\n", data );
  read( file_pipes[0], buffer, BUFSIZ );
  printf( "Read: %s\n", buffer );

  return EXIT_SUCCESS;
}


