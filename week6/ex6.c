#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

int main ( void )
{
  int cpid_1, cpid_2, file_pipes[2];
  char data[BUFSIZ + 1] = "", buffer[BUFSIZ + 1] = "";

  pipe( file_pipes );
  cpid_1 = fork();
  cpid_2 = fork();
   
  if (cpid_1 == 0)
  {
    int pid;
    printf( "Aus das ersste Kind\n" );
    read( file_pipes[0], buffer, BUFSIZ );
    sscanf( buffer, "%d", &pid );
    printf( "\tPID das zweite Kind: [ %d ]\n\tSenden signal zum zweiten Kind\n", pid );
    kill(pid, SIGSTOP);
    printf( "\tSignal ist gesendet\n" );
  }
  else
  {
    printf( "Aus der Vater\n");
    sprintf( data, "%d", cpid_2 );
    write( file_pipes[1], data, strlen( data ) );
    printf( "\tSend zum ersste Kind PID das zweite Kind\n\tWarten auf das Herunterfahren das zweite Kind\n"); 
    waitpid( cpid_2, NULL, 0 );
    printf( "\tDas Herunterfahren das zweite Kind\n");
  }

  return EXIT_SUCCESS;
}

