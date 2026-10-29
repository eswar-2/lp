#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

ssize_t readn(int fd, char *buf, size_t nbytes) {
    size_t left = nbytes;
    char *ptr = buf;

    while (left > 0) {
        ssize_t bytes = read(fd, ptr, left);

        if (bytes == 0)
            break; // EOF

        left -= bytes;
        ptr += bytes;
    }

    return nbytes - left;
}

ssize_t writen(int fd, const char *buf, size_t nbytes) {
    size_t left = nbytes;
    const char *ptr = buf;

    while (left > 0) {
        ssize_t bytes = write(fd, ptr, left);

        left -= bytes;
        ptr += bytes;
    }

    return nbytes - left;
}

int main() {
    int fd = open("file.txt", O_RDONLY);

    char buf[13];
    int n = readn(fd, buf, 12);
    buf[n] = '\0';
    printf("%s\n", buf);
    close(fd);

    fd = open("tmp.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
    char *data = "Reliable I/O";
    writen(fd, data, strlen(data));
    close(fd);
}
