#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct message {
    long type;
    char text[32];
};

int main() {
    int id = msgget(IPC_PRIVATE, IPC_CREAT | 0666);

    if (fork() == 0) {
        struct message msg = {1, "Hello"};
        msgsnd(id, &msg, sizeof(msg.text), 0);
    } else {
        struct message msg;
        msgrcv(id, &msg, 32, 1, 0);
        printf("%s\n", msg.text);
        msgctl(id, IPC_RMID, NULL);
    }
}