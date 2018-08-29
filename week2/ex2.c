#include <stdio.h>
#include <string.h>

main(void)
{
  char str[1000];
  int i;

  printf("Enter string: ");
  gets(str);
  
  for (i = strlen(str); i != -1 ; --i)
  {
    printf("%c", str[i]);
  }
  printf("\n");

  return 0;
}
