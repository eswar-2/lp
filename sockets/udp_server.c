#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);

    struct in_addr inaddr;
    inet_pton(AF_INET, "127.0.0.1", &inaddr);
    addr.sin_addr = inaddr;

    int fd = socket(AF_INET, SOCK_DGRAM, 0);

    int _ = bind(fd, (struct sockaddr *)&addr, sizeof(addr));

    char buf[32];
    struct sockaddr client;
    socklen_t len = sizeof(client);
    int n = recvfrom(fd, buf, 32, 0, &client, &len);
    buf[n] = '\0';
    printf("%s\n", buf);

    char *msg = "Hello client";
    sendto(fd, msg, strlen(msg), 0, &client, len);

    close(fd);
    return 0;
}
