#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd = open("myfifo", O_RDONLY);

    char buf[20];
    read(fd, buf, 20);
    printf("myfifo says: %s\n", buf);

    close(fd);
    return 0;
}