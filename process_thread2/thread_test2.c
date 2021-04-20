#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int counter = 0;

pthread_mutex_t mutex1 =    PTHREAD_MUTEX_INITIALIZER;

void *child(void *arg){
    for(int i=0; i<5 ; i++){
        pthread_mutex_lock(&mutex1);
        int tmp = counter;
        sleep(1);
        counter = tmp+1;
        pthread_mutex_unlock(&mutex1);
        printf("counter = %d\n",counter);
    }
    pthread_exit(NULL);
}

int main(void){
    pthread_t thread1,thread2;
    pthread_create(&thread1,0,child,0);
    pthread_create(&thread2,0,child,0);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return 0;
}