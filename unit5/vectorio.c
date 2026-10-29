#include <bits/types/struct_iovec.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/uio.h>
#include <unistd.h>

int main() {
    int fd = open("tmp.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);

    // Gather I/O
    struct iovec iovec[2];
    iovec[0].iov_base = "Hello ";
    iovec[0].iov_len = 6;
    iovec[1].iov_base = "World";
    iovec[1].iov_len = 5;
    writev(fd, iovec, 2);

    lseek(fd, 0, SEEK_SET);

    // Scatter I/O
    char b1[7], b2[6];
    struct iovec buf[2];
    buf[0].iov_base = b1;
    buf[0].iov_len = 6;
    buf[1].iov_base = b2;
    buf[1].iov_len = 5;

    readv(fd, buf, 2);
    b1[6] = '\0';
    b2[5] = '\0';

    printf("%s%s\n", (char *)buf[0].iov_base, (char *)buf[1].iov_base);

    close(fd);
}