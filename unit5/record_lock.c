#include <bits/types/locale_t.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("file.txt", O_RDWR);

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 12;

    fcntl(fd, F_SETLKW, &lock);
    printf("Locked for 5 sec\n");

    sleep(5);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Unlocked\n");

    // Run the same code two terminals to see the second waiting for lock

    close(fd);
    return 0;
}
