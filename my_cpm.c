#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1 = open(argv[1], O_RDONLY);
  int fd2 = open(argv[2], O_RDONLY);
  
  if (fd1 == -1 | fd2 == -1) {
      perror("Error al obrir els fitxers");
      exit(-1);
  }
