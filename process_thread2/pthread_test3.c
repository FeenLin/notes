#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t can_add,can_mux,can_scranf;

static void *add_func(void *arg);
static void *mux_func(void *arg);
int x,y;

int main(int argc, char *argv[]){

    pthread_t thread;
    int arg[2];
    sem_init(&can_add,0,0);
    sem_init(&can_mux,0,0);
    sem_init(&can_scranf,0,1);

    if (pthread_create(&thread,NULL,add_func,NULL) < 0)
    {
        fprintf(stderr,"create add failed");
        exit(1);
    }

    if (pthread_create(&thread,NULL,mux_func,NULL) < 0)
    {
        fprintf(stderr,"create mux failed");
        exit(1);
    }

    while (1)
    {
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

static void *add_func(void *arg){
    while (1)
    {
        sem_wait(&can_add);
        printf("%d + %d =%d \n",x,y,x+y);
        sem_post(&can_mux);
    }
    return 0;
}

static void *mux_func(void *arg){
    while (1)
    {
        sem_wait(&can_mux);
        printf("%d * %d = %d\n",x,y,x*y);
        sem_post(&can_scranf);
    }
    return 0;
}

