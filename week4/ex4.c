#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
  char cmd[1000] = "";

  for (;;)
  {
    fgets(cmd,1000,stdin);
    if (!strcmp(cmd, "exit")) return 0;
    system(cmd);
  }
}