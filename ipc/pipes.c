#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        char *buf = "Hello";
        write(fd[1], buf, strlen(buf) + 1);

        close(fd[1]);
    } else {
        char buf[20];
        read(fd[0], buf, 20);
        printf("%s\n", buf);

        close(fd[0]);
    }

    return 0;
}