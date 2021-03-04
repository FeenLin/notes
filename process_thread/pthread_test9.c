#include <stdio.h>
#include <pthread.h>

/* pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; */
pthread_mutex_t mutex;

int count;

void * thread_run(void *arg)
{
    int i;
    pthread_mutex_lock(&mutex); //上鎖
    for (i = 0; i < 3; i++) {
        printf("[%#lx]value of count: %d\n", pthread_self(), ++count);
    }
    pthread_mutex_unlock(&mutex); //解鎖
    return 0;
}

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, 0);
    pthread_create(&thread1, NULL, thread_run, 0);
    pthread_create(&thread2, NULL, thread_run, 0);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    pthread_mutex_destroy(&mutex); //破壞鎖
    return 0;
}

//  如果使用了第 4 行的初始化方法，可以删除 23 和 28 行。