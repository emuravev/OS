#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
  struct stat statbuf;
  void *dst, *src;
  int fdin = open("ex1.txt", O_RDONLY), fdout = open("ex1.memcpy.txt", O_RDWR | O_CREAT | O_TRUNC);

  fstat(fdin, &statbuf);
  lseek(fdout, statbuf.st_size - 1, SEEK_SET);
  write(fdout, "", 1);

  src = mmap(0, statbuf.st_size, PROT_READ, MAP_SHARED, fdin, 0);
  dst = mmap(0, statbuf.st_size, PROT_WRITE, MAP_SHARED, fdout, 0);
  memcpy(dst, src, statbuf.st_size);

  msync(dst, statbuf.st_size, MS_SYNC);

  return 0; 
}