#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int data = 0;

void *producer(void *arg) {
    for (int i = 1; i <= 3; ++i) {
        pthread_mutex_lock(&mutex);
        while (data == 1) {
            pthread_cond_wait(&cond, &mutex);
        }

        data = 1;
        printf("%d. Produced: %d\n", i, data);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 1; i <= 3; ++i) {
        pthread_mutex_lock(&mutex);
        while (data == 0) {
            pthread_cond_wait(&cond, &mutex);
        }

        data = 0;
        printf("%d. Consumed: %d\n", i, data);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);

    pthread_t pid, cid;
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    return 0;
}