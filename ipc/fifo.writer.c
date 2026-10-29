#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    mkfifo("myfifo", 0644);

    int fd = open("myfifo", O_WRONLY);

    write(fd, "Hello", 6);
    printf("Sent to myfifo.");

    close(fd);
    return 0;
}