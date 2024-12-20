#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1

int main(int argc, char *argv[]) {
    if (argc < 3) {
        perror("Error: Paràmetres insuficients");
        exit(-1);
    }

    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {
        perror("Error a l'obrir el primer arxiu");
        exit(-1);
    }

    int fd2 = open(argv[2], O_RDONLY);
    if (fd2 < 0) {
        perror("Error a l'obrir el segon arxiu");
        exit(-1);
    }

    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    int bytesRead1, bytesRead2;
    int bytePos = 1;
    int lineNum = 1;

    while ((bytesRead1 = read(fd1, buffer1, BUFFER_SIZE)) > 0 && 
           (bytesRead2 = read(fd2, buffer2, BUFFER_SIZE)) > 0) {
        if (buffer1[0] != buffer2[0]) {
            printf("Diferència trobada al byte %d, línia %d\n", bytePos, lineNum);
            close(fd1);
            close(fd2);
            exit(0);
        }

        if (buffer1[0] == '\n') {
            lineNum++;
        }
        bytePos++;
    }

    if (bytesRead1 != bytesRead2) {
        printf("Diferència trobada: un dels arxius es mes llarg\n");
        close(fd1);
        close(fd2);
        exit(0);
    }

    close(fd1);
    close(fd2);
    return 0;
}

