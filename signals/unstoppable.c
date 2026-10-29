#include <signal.h>
#include <stdio.h>  // printf()
#include <unistd.h> // sleep()

void handler(int sig) { printf("SIGINT ignored"); }

int main() {
    printf("PID: %d\n", getpid());
    // signal(SIGINT, handler);

    struct sigaction sigact;
    sigact.sa_flags = 0;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_handler = handler;

    sigaction(SIGINT, &sigact, NULL);

    int i = 0;
    while (i < 300) {
        printf("%d\n", ++i);
        sleep(1);
    }
}