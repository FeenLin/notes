#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

#define MAX 10
#define BUFFSIZE 5
pthread_mutex_t mutex;
pthread_cond_t condc, condp;
int buff[BUFFSIZE];
int in = 0; int out = 0;

static void *is_producer(void *arg){
    int i;
    for(i = 0; i < MAX;i++){
        pthread_mutex_lock(&mutex);
        while(((in+1)%BUFFSIZE) == out){
            pthread_cond_wait(&condp,&mutex);
        }

        buff[in]=i;
        printf("in_buff[%d] = %d \n",in,buff[in]);
        
        in = (in+1)%BUFFSIZE;
        pthread_cond_signal(&condc);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(0);
}
static void *is_conusmer(void *arg){
    int i;
    for(i=0 ; i < MAX;i++){
        pthread_mutex_lock(&mutex);
        while(in == out){
            pthread_cond_wait(&condc,&mutex);
        }
        printf("out_buff[%d] = %d\n",out,buff[out]);
        
        out =(out+1)%BUFFSIZE;
        buff[out]=0;
        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(0);
}

int main(int argc,char *argv[]){

    printf("step 1\n");
    pthread_t pro,con;
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&condp,NULL);
    pthread_cond_init(&condc,NULL);
    printf("step 2\n");
    pthread_create(&pro, NULL, is_producer, NULL);
    pthread_create(&con, NULL, is_conusmer, NULL);
    printf("step 3\n");
    pthread_join(pro,NULL);
    pthread_join(con,NULL);
    printf("step 4\n");
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condp);
    pthread_cond_destroy(&condc);

    return 0;
}