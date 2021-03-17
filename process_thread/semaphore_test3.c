#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>

typedef void* handler;

sem_t can_add;
sem_t can_mux;
sem_t can_scranf;

static handler add_func(handler arg);
static handler mux_func(handler arg);

int x,y;

int main(int argc , char* argv[]){

    pthread_t thread;
    int arg[2];
    sem_init(&can_add,0,0);
    sem_init(&can_mux,0,0);
    sem_init(&can_scranf,0,1);
    if(pthread_create(&thread,NULL,add_func,NULL)< 0){
        fprintf(stderr,"creat add failed");
        exit(1);
    }

    if(pthread_create(&thread,NULL,mux_func,NULL) < 0){
        fprintf(stderr,"creat mux failed");
        exit(1);
    }

    while(1){
        sem_wait(&can_scranf);
        printf("input 2 number: ");
        scanf("%d%d",&x,&y);
        sem_post(&can_add);
    }
    sem_destory(can_add);
    sem_destroy(can_mux);
    sem_destroy(can_scranf);
    return 0;
}

static handler add_func(handler arg){
    while(1){
        sem_wait(&can_add);
        printf("%d + %d = %d \n",x,y,x+y);
        sem_post(&can_mux);
    }
    return 0;
}

static handler mux_func(handler arg){
    while(1){
        sem_wait(&can_mux);
        printf("%d * %d = %d \n",x,y,x*y);
        sem_post(&can_scranf);
    }
    return 0;
}

