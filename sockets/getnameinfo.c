#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>

int main() {
    struct sockaddr_in saddr;
    saddr.sin_port = htons(80);
    saddr.sin_family = AF_INET;

    struct in_addr in_ad;
    inet_pton(AF_INET, "172.66.147.243", &in_ad);
    saddr.sin_addr = in_ad;

    char host[32], serv[32];
    getnameinfo((struct sockaddr *)&saddr, sizeof(saddr), host, 32, serv, 32,
                0);

    printf("%s : %s\n", host, serv);
}