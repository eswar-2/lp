#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void *handler(void *arg) {
    int cfd = *(int *)arg;

    char buf[32];
    int n = recv(cfd, &buf, 32, 0);
    buf[n] = '\0';
    printf("Received: %s\n", buf);

    char *msg = "Hello";
    send(cfd, msg, strlen(msg), 0);

    close(cfd);
    free(arg);
    return NULL;
}

int main() {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);

    struct in_addr inad;
    inet_pton(AF_INET, "127.0.0.1", &inad);
    addr.sin_addr = inad;

    int fd = socket(AF_INET, SOCK_STREAM, 0);

    int _ = bind(fd, (struct sockaddr *)&addr, sizeof(addr));

    listen(fd, 5);

    while (1) {
        struct sockaddr client;
        socklen_t len = sizeof(client);
        int *cfd = malloc(sizeof(int));
        *cfd = accept(fd, &client, &len);

        pthread_t tid;
        pthread_create(&tid, NULL, handler, cfd);
        pthread_detach(tid);
    }
}