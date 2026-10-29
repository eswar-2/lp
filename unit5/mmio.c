#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    int fd = open("file.txt", O_RDWR);
    char *ptr = mmap(NULL, 32, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    printf("%s\n", ptr); // Read the file directly from memory
    char *data = "Hello world";
    memcpy(ptr, data, strlen(data) + 1); // Write the file directly from memory

    munmap(ptr, 32);
    close(fd);
    return 0;
}