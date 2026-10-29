#include <stdio.h>
#include <sys/stat.h>

int main(int argc, const char **argv) {
    if (argc < 2) {
        printf("Usage: ./stats <filename>\n");
        return 1;
    }

    struct stat stats;
    stat(argv[1], &stats);

    printf("UID: %d\n", stats.st_uid);
    printf("GID: %d\n", stats.st_gid);
    printf("Inode: %ld\n", stats.st_ino);
    printf("Size: %ld bytes\n", stats.st_size);
}