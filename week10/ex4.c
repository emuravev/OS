#include <stdio.h>
#include <dirent.h>

int main ( void )
{
  DIR *dirp;
  struct dirent *dp;
  char str [1000] = {0};
  int size = 0, ino, is_d_ino = 0;

  dirp = opendir("./tmp/");
  while ((dp = readdir(dirp))!=NULL)
  {
    if (!is_d_ino && dp->d_ino == ino)
    {
      is_d_ino = 1;
      strcat(str, " linked this");
      strcat(str, "\n");
      strcat(str, "-> ");
      strcat(str, dp->d_name);
    }
    ino = dp->d_ino;
    if (!is_d_ino) 
    {
      strcpy(str, dp->d_name);
    }
  }
  closedir(dirp);
  printf(str);
  printf("\n");
}
