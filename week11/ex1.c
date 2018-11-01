#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
  struct stat statbuf;
  void *dst;
  int fdin = open("ex1.txt", O_RDWR);
  
  fstat(fdin, &statbuf);
  lseek(fdin, strlen("This is a nice day\n") - 1, SEEK_SET);
  write(fdin, "", 1);

  dst = mmap(0, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdin, 0);

  memset(dst, '\0', statbuf.st_size);
  memcpy(dst, "This is a nice day\n", strlen("This is a nice day\n"));

  msync(dst, strlen("This is a nice day\n"), MS_SYNC);

  return 0;
}