#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

pthread_cond_t c  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int done          = 0;

void *child(void *arg) {
    sleep(1);
    printf("\n--- running child thread ---\n\n");
    sleep(1);
    pthread_mutex_lock(&m);
    done = 1;
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
    printf("\n--- unlock ---\n\n");
    return NULL;
}

int main() {
    pthread_t p;
    printf("main thread start ...\n");
    assert(pthread_create(&p, NULL, child, NULL) == 0); // return 0 means success
    pthread_mutex_lock(&m);
    while (done == 0) {
        pthread_cond_wait(&c, &m);
    }
    pthread_mutex_unlock(&m);
    printf("main thread end ...\n");
    return 0;
}