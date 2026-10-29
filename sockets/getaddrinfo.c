#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>

int main() {
    struct addrinfo hints, *res;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int _ = getaddrinfo("example.com", "80", &hints, &res);

    struct sockaddr_in *in_addr = (struct sockaddr_in *)res->ai_addr;
    struct in_addr *addr = &in_addr->sin_addr;

    char ip[32];
    inet_ntop(AF_INET, addr, ip, sizeof(ip));
    printf("%s\n", ip);

    return 0;
}