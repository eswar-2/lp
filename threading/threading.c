#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *worker(void *arg) {
    sleep(1);
    printf("Worker\n");

    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, worker, NULL);

    printf("Thread started\n");
    fflush(stdout);

    // pthread_detach(tid);
    // sleep(1);

    pthread_join(tid, NULL);
}