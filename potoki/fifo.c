#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define FIFO_NAME "/tmp/my_fifo"

int main() {
    pid_t pid1, pid2;
    char buffer[100];

    mkfifo(FIFO_NAME, 0666); //0666 daje uprawnienia do odczytu i zapisu

    pid1 = fork();  //zapis do potoku
    if (pid1 == 0) {
        int fd = open(FIFO_NAME, O_WRONLY);
        char msg[] = "Hello FIFO";
        write(fd, msg, strlen(msg));
        close(fd);
        exit(0);
    }

    pid2 = fork();  //odczyt z potoku
    if (pid2 == 0) {
        int fd = open(FIFO_NAME, O_RDONLY);
        read(fd, buffer, sizeof(buffer));
        printf("Process 2 read: %s\n", buffer);
        close(fd);
        exit(0);
    }

    wait(NULL);
    wait(NULL);

    return 0;
}
