//Assumption: Buffer SIZE = 1
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>


#define SHARED 1            // sem_init 第二個參數用( 0:thread不共享    1:thread共享)
void *Producer(); 
void *Consumer(); 
sem_t empty, full, sm;  
int data; 

int main(){
    pthread_t ptid, ctid; 
    printf("\nMain Started");
    sem_init(&empty, SHARED, 1);    // 初始化 semphore empty =1 當作互斥鎖使用
    sem_init(&full, SHARED, 0);     // 初始化 semphore full  =0 當作互斥鎖使用
    sem_init(&sm, SHARED, 1);       // 初始化 semphore sm    =1 CRITICAL SECTION
    pthread_create(&ptid,NULL,Producer,NULL); 
    pthread_create(&ctid,NULL,Consumer,NULL); 
    pthread_join(ptid,NULL); 
    pthread_join(ctid,NULL); 
    printf("\nMain done\n");
}

void *Producer(){

    int produced;
    printf("\nProducer created");
    printf("\nProducer id is %ld\n",pthread_self()); //print thread id (POSIX thread ID)
    for(produced=0;produced<100;produced++)
    {
    sem_wait(&empty);
    // LOCK-starts
       sem_wait(&sm);
           //CRITICAL SECTION STARTS
                   data=produced;
           //CRITICAL SECTION ENDS
       sem_post(&sm);
    //LOCK-ends
    sem_post(&full);
    printf("\nProducer: %d",data);
    }
}

void *Consumer(){
    int consumed, total=0;
    printf("\nConsumer created\n");
    printf("\nConsumer id is %ld\n",pthread_self());
    for(consumed=0;consumed<100;consumed++)
    {
    sem_wait(&full);
    //LOCK-starts
       sem_wait(&sm);
             //CRITICAL SECTION STARTS
                     total=total+data;
             //CRITICAL SECTION ENDS
       sem_post(&sm);
    //LOCK-ends
    sem_post(&empty);
    printf("\nConsumed: %d",data);
}

printf("\nThe total of 100 iterations is %d\n",total);
}