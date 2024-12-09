#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
      fprintf(stderr, "Error: Falta el nom de l'arxiu.\n");
      return -1;
  }
  int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd == -1) {
      perror("Error al crear l'arxiu");
      exit(-1);
  }
  char buffer[1];
  while (read(STDIN_FILENO, buffer, 1) > 0) {


