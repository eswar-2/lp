#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    char *ptr = shmat(shmid, NULL, 0);

    if (fork() == 0) {
        strcpy(ptr, "Hello");
    } else {
        wait(NULL);
        printf("%s\n", ptr);
        shmctl(shmid, IPC_RMID, NULL);
    }
}