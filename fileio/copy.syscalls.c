#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    int cd = open("copy.txt", O_CREAT | O_TRUNC | O_WRONLY);

    int buf_size = 4;
    char buf[buf_size];
    int n;
    while ((n = read(fd, &buf, buf_size)) != 0) {
        write(cd, buf, n);
    }

    close(fd);
    close(cd);

    return 0;
}